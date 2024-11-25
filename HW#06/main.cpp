#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include <vector>
using namespace std;
class UI { 
    static int n; 
public:
    static void start(); 
    static int menu(); 
    static int insert(); 
    static int del(); 
};
int UI::n = 0;
void UI::start() {
    cout << "그래픽 에디터입니다." << endl;
}
int UI::menu() { 
    cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
    cin >> n;
    return n;
}
int UI::insert() { 
    cout << "선:1, 원:2, 사각형:3 >> ";
    cin >> n;
    return n;
}
int UI::del() { 
    cout << "삭제하고자 하는 도형의 인덱스 >> ";
    cin >> n;
    return n;
}
class GraphicEditor {
    vector<Shape*> v;
    vector<Shape*>::iterator it;
public:
    GraphicEditor() {}
    void insert() {
        int n = UI::insert();
        if (n == 1)
            v.push_back(new Line());
        else if (n == 2)  
            v.push_back(new Circle());
        else if (n == 3) 
            v.push_back(new Rectangle());
        else cout << "입력 에러" << endl;
    }
    void deleteShape() {
        int n = UI::del();
        Shape* del;
        it = v.begin();
        for (int i = 0; i < n; ++i)
            ++it;
        del = *it;
        it = v.erase(it);
        delete del;
    }
    void showAll() {
        for (int i = 0; i < v.size(); ++i) {
            cout << i << ": ";
            v[i]->paint();
        }
    }
    void start() {
        UI::start();
        for (;;) {
            int m = UI::menu();
            if (m == 1) 
                insert();
            else if (m == 2) 
                deleteShape();
            else if (m == 3)  
                showAll();
            else if (m == 4) break;
            else cout << "입력 에러 " << endl;
        }
    }
};
int main() {
    GraphicEditor* g = new GraphicEditor;
    g->start();
    delete g;
}