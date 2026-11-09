module tag;
import <iostream>;
import <string>;
import <utility>;

Tag::Tag(const std::string &type): type{type}, parent{nullptr}, children{nullptr}{
  // this -> type = type;
  this -> id = "";
  this -> value = "";
  this -> childrenLength = 0;
  this -> childrenCapacity = 0;
}

Tag::Tag(const Tag &other): parent{other.parent}, children{other.children ? new Tag *[other.childrenCapacity] : nullptr}{
  this -> type = other.type;
  this -> id = other.id;
  this -> value = other.value;
  if(this->children != nullptr){
    for(int i=0; i<other.childrenLength; ++i) this->children[i] = new Tag(other.children[i] -> type);
  }
  this -> childrenLength = other.childrenLength;
  this -> childrenCapacity = other.childrenCapacity;
}

Tag::Tag(Tag &&other): parent{other.parent}, children{other.children ? new Tag *[other.childrenCapacity] : nullptr}{
  this -> type = other.type;
  this -> id = other.id;
  this -> value = other.value;
  if(this->children != nullptr){
    for(int i=0; i<other.childrenLength; ++i) this->children[i] = new Tag(other.children[i] -> type);
  }
  this -> childrenLength = other.childrenLength;
  this -> childrenCapacity = other.childrenCapacity;
  delete &other;
}

Tag::~Tag(){
  this -> parent = nullptr; // unless the parent will be deleted
  for(int i=0; i< this -> childrenLength; ++i) delete this->children[i];
  delete [] this -> children;
}

Tag &Tag::operator=(const Tag &other){
  Tag temp = other;
  std::swap(this -> type, temp.type);
  std::swap(this -> id, temp.id);
  std::swap(this -> value, temp.value);
  std::swap(this -> parent, temp.parent);
  std::swap(this -> children, temp.children);
  std::swap(this -> childrenLength, temp.childrenLength);
  std::swap(this -> childrenCapacity, temp.childrenCapacity);
  return *this;
}

Tag &Tag::operator=(Tag &&other){
  Tag temp = Tag(other);
  std::swap(this -> type, temp.type);
  std::swap(this -> id, temp.id);
  std::swap(this -> value, temp.value);
  std::swap(this -> parent, temp.parent);
  std::swap(this -> children, temp.children);
  std::swap(this -> childrenLength, temp.childrenLength);
  std::swap(this -> childrenCapacity, temp.childrenCapacity);
  delete &other;
  return *this;
}

const std::string &Tag::getType() const{
  return this->type;
}

const std::string &Tag::getId() const{
  return this->id;
}
// Sets the value of the id field
void Tag::setId(const std::string &_id){
  this->id = _id;
}
// Returns the value of the value field
const std::string &Tag::getValue() const{
  return this->value;
}
// Sets the value of the value field
void Tag::setValue(const std::string &_value){
  this->value = _value;
}
// Returns the value of the parent field
Tag *Tag::getParent() const{
  return this->parent;
}
// Sets the value of the parent field
void Tag::setParent(Tag *_parent){
  this->parent = _parent;
}

// Prints this tag to out in the following format:
// <type id='id' value='value'>
//   ...children
// </type>
// Note that the indentLevel starts at 0 for the first tag,
// so, the first tag is printed without any trailing spaces.
// For each children level, increase the indentLevel by 1.
// For each indentLevel, add two spaces to the beginning of the line
// If the id or value attributes are empty (""), do not print them.
// If this tag does not have children, don't print anything for the ...children line.

std::ostream &operator<<(std::ostream &out, const Tag &tag){
  tag.print(out, 0);
  return out;
}
void Tag::print(std::ostream &out, int indentLevel) const{
  for(int i=0; i < indentLevel; ++i){
    out << "  ";
  }

  out << "<" << tag->type;
  if(tag -> id != ""){
    out << " id='" << tag -> id << "' ";
  }
  if(tag->value != ""){
    out << " value='" << tag->value << "' ";
  }
  out << ">" << std::endl;

  for(int i=0; i < this -> childrenLength; ++i){
    this -> children[i] -> print(out, ++indentLevel);
  }
  
  for(int i=0; i < indentLevel-1; ++i){
    out << "  ";
  }
  out << "</" << this -> type << ">" << std::endl;
}

// Adds other to the children array.
// Create or resize the array if needed.
void Tag::addChild(Tag *other){
  if(childrenCapacity == 0){
    this -> childrenCapacity = 1;
    this -> children = new Tag *[1];
  }
  if(this->childrenLength >= this -> childrenCapacity){
    this -> childrenCapacity = this -> childrenCapacity * 2;
  }
  this-> children[childrenLength] = other;
  this -> childrenLength ++;
}
// Removes other from the children array.
// If other is not in the array, does nothing.
// (Does NOT delete other).
void Tag::removeChild(Tag *other){
  for(int i=0; i<this->childrenLength; ++i){
    if(this->children[i]==other) this -> children[i] = nullptr;
  }

}
// Returns the first tag in the children array whose type is equal to the supplied parameter.
// If no such tag is found, returns nullptr.
Tag *Tag::findChild(std::string &type){
  for(int i=0; i<this->childrenLength; ++i){
    if(this->children[i]->type==type) return {this->children[i]};
  }
  return {nullptr};
}
// Returns the first tag in the children array whose id is equal to the supplied parameter.
// If no such tag is found, returns nullptr.
Tag *Tag::findChildId(std::string &id){
  for(int i=0; i<this->childrenLength; ++i){
    if(this->children[i]->id==id) return {this->children[i]};
  }
  return {nullptr};
}

// Returns an iterator to the start of the children array.
TagIterator Tag::begin() const{
  // TagIterator *begin = new TagIterator{this->children};
  return TagIterator{this->children};
}
// Returns an iterator past the end of the children array.
TagIterator Tag::end() const{
  // TagIterator *end = new TagIterator{&this->children[this->childrenLength-1]};
  return TagIterator{&(this->children[this->childrenLength-1])+1};
}

TagIterator::TagIterator(Tag **t): t{t} {}

// Returns the tag that this iterator is currently pointing to
Tag *TagIterator::operator*() const{
  return *this->t;
}
// Advances the iterator
TagIterator TagIterator::operator++(){
  this -> t += 1;
  return TagIterator(this -> t);
}
// Compares this iterator with other; returns true if they point to the same array position.
bool TagIterator::operator==(const TagIterator &other) const{
  return {this -> t == other.t};
}
// Compares this iterator with other; returns true if they do not point to the same array position.
bool TagIterator::operator!=(const TagIterator &other) const{
  return {this -> t != other.t};
}