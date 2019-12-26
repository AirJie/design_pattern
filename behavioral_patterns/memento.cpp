#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

enum GameStatus { kFail = 0, kSuccess };

class GameMemento {
 public:
  GameMemento(int level, GameStatus st) : level_(level), st_(st) {}
  int GetGameLevel() { return level_; }
  GameStatus GetGameStatus() { return st_; }

 private:
  int level_;
  GameStatus st_;
};

class Game {
 public:
  Game() : level_(0), st_(kFail) {}
  int GetGameLevel() { return level_; }
  GameStatus GetGameStatus() { return st_; }
  void LoseGame() {
    cout << "lose this game level:" << level_ << endl;
    st_ = kFail;
  }
  void DefeatGame() {
    level_++;
    cout << "defeat this level and next level:" << level_ << endl;
    st_ = kSuccess;
  }
  GameMemento* SaveGameStatus() { return new GameMemento(level_, st_); }
  void RecoverGame(GameMemento* gmem) {
    level_ = gmem->GetGameLevel();
    st_ = gmem->GetGameStatus();
  }

 private:
  int level_;
  GameStatus st_;
};

class GameCaretake {
 public:
  void SetMemento(GameMemento* gmem) { gmem_ = gmem; }
  GameMemento* GetMemento() { return gmem_; }

 private:
  GameMemento* gmem_;
};

int main() {
  Game game;
  cout << "game level:" << game.GetGameLevel() << endl;
  cout << "game status" << game.GetGameStatus() << endl;
  game.DefeatGame();
  GameCaretake* ctaker = new GameCaretake();
  ctaker->SetMemento(game.SaveGameStatus());
  game.LoseGame();
  game.DefeatGame();
  cout << "current level:" << game.GetGameLevel() << endl;

  cout << "play again" << endl;
  game.RecoverGame(ctaker->GetMemento());
  cout << "game level:" << game.GetGameLevel() << endl;
  cout << "game status" << game.GetGameStatus() << endl;
}