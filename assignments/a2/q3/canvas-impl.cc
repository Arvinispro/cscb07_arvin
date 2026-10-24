module canvas;
import <iostream>;
import <utility>;

Canvas::Canvas(int width, int height, char ch): width{width}, height{height}{
  this -> rows = new char *[width];
  for(int i=0; i<width; i++) this -> rows[i] = new char[height];
  
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      this -> rows[i][j] = ch;
    }
  }
}

Canvas::Canvas(const Canvas &other): width{other.width}, height{other.height}{
  if(other.isEmpty()){
    this -> width = 0;
    this -> height=0;
    this -> rows = nullptr;
    return;
  }
  this -> rows = new char *[other.width];
  for(int i=0; i<width; i++) this -> rows[i] = new char[other.height];

  for(int i=0;i<other.width;i++){
    for(int j=0;j<other.height;j++){
      this -> rows[i][j] = other.rows[i][j];
    }
  }
}

Canvas::~Canvas(){
  for(int i=0;i<this->width;i++){
    delete [] this->rows[i];
  }
}

Canvas &Canvas::operator=(const Canvas &other){
  if(this == &other) return *this;

  if(other.isEmpty()){
    this -> width = 0;
    this -> height=0;
    this -> rows = nullptr;
    return *this;
  }
  Canvas temp = other;
  std::swap(this -> width, temp.width);
  std::swap(this -> height, temp.height);
  std::swap(this -> rows, temp.rows);

  return *this;
}

Canvas::Canvas(Canvas &&other):width{other.width}, height{other.height}{
  if(other.isEmpty()){
    this -> width = 0;
    this -> height=0;
    this -> rows = nullptr;
    return;
  }
  std::swap(this -> rows, other.rows);
  other.width = 0;
  other.height=0;
  other.rows = nullptr;
}

Canvas &Canvas::operator=(Canvas &&other){
  if(other.isEmpty()){
    this -> width = 0;
    this -> height=0;
    this -> rows = nullptr;
    return *this;
  }
  std::swap(this -> width, other.width);
  std::swap(this -> height, other.height);
  std::swap(this -> rows, other.rows);
  other.width = 0;
  other.height=0;
  other.rows = nullptr;
  return *this;
}

int Canvas::getWidth() const{
  return this->width;
}
int Canvas::getHeight() const{
  return this->height;
}
bool Canvas::isEmpty() const{
  return {this->rows == nullptr};
}

char Canvas::get(int x, int y) const{
  return {this->rows[x][y]};
}
void Canvas::set(int x, int y, char ch){
  this -> rows[x][y] = ch;
}
void Canvas::fill(char ch){
  for(int i=0;i<this->width;i++){
    for(int j=0;j<this->height;j++){
      this -> rows[i][j] = ch;
    }
  }
}

void Canvas::print(std::ostream &out) const{
  if(this->isEmpty()) {
    out << "(empty)";
  }
  else{
    out << "+";
    for(int i=0;i<this->width;i++) out<<"-";
    out << "+"<<std::endl;

    for(int j=0;j<this->height;j++){
      out<<"|";
      for(int i=0;i<this->width;i++){
        out << this->rows[i][j];
      }
      out<<"|"<<std::endl;
    }
    out << "+";
    for(int i=0;i<this->width;i++) out<<"-";
    out << "+"<<std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const Canvas &canvas){
  canvas.print(out);
  return out;
}

