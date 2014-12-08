#include "Game.h"


Game::Game()
{
  flag = CONTINUE;
  p = new Player;
}


Game::~Game()
{
  delete p;
}

void Game::begin(){
  srand(time(NULL));
  intro();
  characterCreation();
  while (flag == CONTINUE){
    std::cout << "";
    std::cin.get();
  }
}

void Game::intro(){

}

void Game::characterCreation(){
  std::string r,j;
  int c;
  clear();
  std::cout << "\nChoose a Race\n" <<
    "---------------------------------\n" <<
    "1. Human\n"<<
    "2. Elf\n";
  std::cin >> c;
  if (c == 1){
    r = "Human";
  }
  else if (c == 2){
    r = "Elf";
  }
  else if (c == 3){
    r = "Dwarf";
  }
  clear();
  std::cout << "\nChoose a Class\n" <<
    "---------------------------------\n" <<
    "1. Warrior\n" <<
    "2. Mage\n";
  std::cin >> c;
  if (c == 1){
    j = "Warrior";
  }
  else if (c == 2){
    j = "Mage";
  }
}

void Game::displayArt(std::string pic){
  std::string s;
  std::fstream file(pic.c_str(),std::fstream::in);
  while (getline(file, s)){
    std::cout << s;
    std::cout << "\n";
  }
  file.close();
}

void Game::clear(){
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD coord = { 0, 0 };
  DWORD count;

  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(hStdOut, &csbi);

  FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
  SetConsoleCursorPosition(hStdOut, coord);
}