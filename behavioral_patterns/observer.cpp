#include <iostream>
#include <list>
#include <string>

using namespace std;

class Observer {
 public:
  Observer() {}
  virtual ~Observer() {}
  virtual void Update() {}
};

class Blog {
 public:
  virtual ~Blog() {}
  void Attach(Observer *observer) { observer_.push_back(observer); }
  void Remove(Observer *observer) { observer_.remove(observer); }
  void Notify() {
    list<Observer *>::iterator iter = observer_.begin();
    for (; iter != observer_.end(); iter++) (*iter)->Update();
  }
  virtual void SetStatus(string st) { status_ = st; }
  virtual string GetStatus() { return status_; }

 private:
  list<Observer *> observer_;

 protected:
  string status_;
};

class Twitter : public Blog {
 public:
  Twitter(string name) : name_(name) {}
  ~Twitter() {}
  void SetStatus(string st) { Blog::status_ = st; }
  string GetStatus() { return Blog::status_; }

 private:
  string name_;
};

class ObserverBlog : public Observer {
 public:
  ObserverBlog(string name, Blog *blog) : name_(name), blog_(blog) {}
  ~ObserverBlog() {}
  void Update() {
    string st = blog_->GetStatus();
    cout << "name:" << name_ << " status:" << st << endl;
  }

 private:
  string name_;
  Blog *blog_;
};

int main() {
  Blog *blog = new Twitter("new blog");
  ObserverBlog *obser = new ObserverBlog("Taylor Swift", blog);
  blog->Attach(obser);
  blog->SetStatus("show a picture");
  blog->Notify();
  delete blog, obser;

  return 1;
}