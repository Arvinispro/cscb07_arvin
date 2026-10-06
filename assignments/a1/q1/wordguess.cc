import <iostream>;
import <fstream>;
import <string>;
import <sstream>;

bool validate(std::string word){
  int count{0};
  std::string seen;
  for(char c:word){

    if (count > 5) return false;
    for (char s:seen){
      if (s == c) return false;
    }
    seen += c;
    std::cout << "seen: " << seen << std::endl;
    count ++;
  }
  if (count < 5) return false;
  return true;
}

int main(int argc, char* argv[]){
  if (argc != 2) {
    std::cerr << "usage: wordguess <filename>" << std::endl;
    return 1;
  }
  //open file 
  std::ifstream f{argv[1]};
  std::string read;
  if(f.is_open()){
    f >> read;
  }
  else{
    std::cerr << argv[1] << " cannot be opened" << std::endl;
    return 1;
  }
  //validate secret word
  if (!validate(read)){
    std::cerr << "the secret word is invalid" << std::endl;
    return 1;
  } 

  
  const std::string secret = read;
  //guess
  std::string input;
  while(true){
    input = "";
    if(std::cin.eof()) break;
    std::cin >> input;

    //validate input
    if (!validate(input)){
      std::cout << "invalid guess" << std::endl;
      continue;
    } 

    if(input == secret){
      std::cout << "you guessed correctly!" << std::endl;
      break;
    }
    else{
      int check[5]{0};
      for(char c:input){
        for(int i; i<5; i++){
          if(c==secret[i] && check[i]==0){
            check[i] = 1;
          }
        }
      }
      int match;
      for(int i; i<5; i++) match += check[i];
      std::cout << match << " letters match" << std::endl;
    }
  }
  return 0;
}