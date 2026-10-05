import <iostream>;
import <sstream>;

bool validate(std::string word){
  int count{0}
  std::string seen;
  for(char c:word){
    if (count > 5) return false
    for (char s:seen){
      if (s == c) return false;
    }
    c >> seen;
    count ++;
  }
  if (count < 5) return false;
  return true;
}

int main(int argc, char* argv[]){
  int arg;
  if (argc == 1){
    arg = 0;
  }
  else if(argc == 2){
    arg = 1;
  } 
  else std::cer << "“usage: wordguess " << argv[0] << std::endl;

  //open file 
  if(std::ifstream f{argv[arg]}){
    std::string secret;
    f >> secret;
  }
  else{
    std::cer << argv[arg] << " cannot be opened" << std::endl;
  }
  //validate secret word
  if !(validate(secret)) std::cer << "the secret word is invalid" << std::endl;
  
  //guess
  std::string input;
  while(true){
    input = "";
    if(std::cin.eof()) break;
    std::cin >> input;

    //validate input
    if !(validate(input)){
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
}