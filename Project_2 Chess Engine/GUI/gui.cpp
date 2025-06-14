// chess_sdl.cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

#include "../Pieces/Pieces.cpp"
#include "../Board/Board.cpp"
#include "../Engine/Engine.cpp"
#include "../Minimax/Minimax.cpp"

#include "../MovePolicy/MovePolicy.cpp"
#include "../MovePolicy/KingCheckPolicy.cpp"
#include "../MovePolicy/SpecialMoves.cpp"
#include "../MovePolicy/FigureMoves.cpp"


const int TILE_SIZE = 80;
const int BOARD_SIZE = 8;
const int WINDOW_SIZE = TILE_SIZE * BOARD_SIZE;

std::vector<int> selected_tiles;

int selectedX = -1;
int selectedY = -1;
int old_idx = 0;

int turn = 1;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
std::map<std::string, SDL_Texture*> textures;

Minimax board;

bool loadTextures() {
    std::string names[] = {"wp", "wr", "wn", "wb", "wq", "wk", "bp", "br", "bn", "bb", "bq", "bk"};
    for (const auto& name : names) {
        std::string path = "assets/" + name + ".png";
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (!surface) {
            std::cerr << "Failed to load " << path << "\n";
            return false;
        }
        textures[name] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    return true;
}

std::string get_piece_texture_key(Figure* fig) {
    if (!fig) return "";

    int type = fig->identifier;   // np. 1 dla pionka
    int color = fig->color; // 1 (biały), -1 (czarny)

    char code = 'x';
    switch (type) {
        case 1: code = 'p'; break;
        case 2: code = 'r'; break;
        case 3: code = 'n'; break;
        case 4: code = 'b'; break;
        case 5: code = 'k'; break;
        case 6: code = 'q'; break;
    }

    std::string key = (color == 1 ? "w" : "b");
    key += code;
    return key;
}

void drawBoard() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            int idx = (7 - y) * 8 + (7 - x);
            SDL_Rect tile = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
            bool isWhite = (x + y) % 2 == 0;
            
            if(std::find(selected_tiles.begin(), selected_tiles.end(), idx) != selected_tiles.end()){
                SDL_SetRenderDrawColor(renderer, 40, 200, 40, 255);
            }else{
                SDL_SetRenderDrawColor(renderer, isWhite ? 240 : 100, isWhite ? 217 : 100, isWhite ? 181 : 100, 255);
            }
            
            SDL_RenderFillRect(renderer, &tile);

            if (x == selectedX && y == selectedY) {
                SDL_SetRenderDrawColor(renderer, 100, 200, 100, 160);
                SDL_RenderFillRect(renderer, &tile);
            }
            Figure* fig = board.board[idx];
            if (fig) {
                std::string key = get_piece_texture_key(fig);
                if (textures.count(key)) {
                    SDL_RenderCopy(renderer, textures[key], nullptr, &tile);
                }
            }

        }
    }
}

void handleSecondMouseClick(int mouseX, int mouseY) {
    selectedX = -1;
    selectedY = -1;
    selected_tiles.clear();
}

void handleMouseClick(int mouseX, int mouseY) {
    selectedX = mouseX / TILE_SIZE;
    selectedY = mouseY / TILE_SIZE;

    int new_idx = (7 - selectedY) * 8 + (7 - selectedX);

    if(std::find(selected_tiles.begin(), selected_tiles.end(), new_idx) != selected_tiles.end()){
        board.move(old_idx, new_idx, 1);
        turn *= -1;
        return;
    }else if(board.board[new_idx] != nullptr){
        old_idx = (7 - selectedY) * 8 + (7 - selectedX);
        selected_tiles = board.show_available_moves(board.board, board.board[old_idx], 1);
    }

}




int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "SDL init failed\n";
        return 1;
    }

    window = SDL_CreateWindow("SDL2 Chess Board", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE, WINDOW_SIZE, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!loadTextures()) return 1;

    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (turn == 1){
                if (e.type == SDL_QUIT)
                    running = false;
                else if (e.type == SDL_MOUSEBUTTONDOWN){
                    if (e.button.button == SDL_BUTTON_LEFT){
                        handleMouseClick(e.button.x, e.button.y);
                    }else if (e.button.button == SDL_BUTTON_RIGHT){
                        handleSecondMouseClick(e.button.x, e.button.y);
                    }
                }
            }else if(turn == -1){
                std::pair<int, int> best_opponent_move = board.get_best_move(board.board, 3, -1);
                board.move(best_opponent_move.first, best_opponent_move.second, -1);
                turn *= -1;
            }

        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        drawBoard();
        SDL_RenderPresent(renderer);
    }

    for (auto& t : textures) SDL_DestroyTexture(t.second);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}