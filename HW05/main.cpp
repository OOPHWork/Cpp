#include <iostream>
using namespace std;

// Shape 추상 클래스
class Shape {
protected:
    Shape* next; // 다음 도형을 가리키는 포인터
public:
    Shape() : next(nullptr) {} // 생성자에서 next 초기화
    virtual ~Shape() {}
    virtual void draw() const = 0; // 순수 가상 함수
    Shape* add(Shape* p) {
        this->next = p;
        return p;
    }
    Shape* getNext() const { return next; }
};

// Line 클래스
class Line : public Shape {
public:
    void draw() const override {
        cout << "Line" << endl;
    }
};

// Circle 클래스
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Circle" << endl;
    }
};

// Rect 클래스
class Rect : public Shape {
public:
    void draw() const override {
        cout << "Rectangle" << endl;
    }
};

// GraphicEditor 클래스
class GraphicEditor {
private:
    Shape* head; // 연결 리스트의 시작점
public:
    GraphicEditor() : head(nullptr) {} // 생성자에서 head 초기화

    void insertShape() {
        cout << "선:1, 원:2, 사각형:3 >> ";
        int choice;
        cin >> choice;

        Shape* newShape = nullptr;
        switch (choice) {
        case 1:
            newShape = new Line();
            break;
        case 2:
            newShape = new Circle();
            break;
        case 3:
            newShape = new Rect();
            break;
        default:
            cout << "잘못된 선택입니다." << endl;
            return;
        }

        if (!head) {
            head = newShape; // 첫 번째 도형일 경우 head로 설정
        } else {
            Shape* temp = head;
            while (temp->getNext()) {
                temp = temp->getNext();
            }
            temp->add(newShape); // 연결 리스트의 끝에 새 도형 추가
        }
    }

    void deleteShape() {
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        int index;
        cin >> index;

        if (!head) {
            cout << "삭제할 도형이 없습니다." << endl;
            return;
        }

        if (index == 0) {
            Shape* temp = head;
            head = head->getNext();
            delete temp;
            cout << "삭제 완료" << endl;
            return;
        }

        Shape* temp = head;
        Shape* prev = nullptr;
        int count = 0;

        while (temp && count < index) {
            prev = temp;
            temp = temp->getNext();
            count++;
        }

        if (!temp) {
            cout << "잘못된 인덱스입니다." << endl;
        } else {
            prev->add(temp->getNext()); // 이전 노드가 다음 노드를 가리키도록 설정
            delete temp;
            cout << "삭제 완료" << endl;
        }
    }

    void showShapes() const {
        if (!head) {
            cout << "저장된 도형이 없습니다." << endl;
            return;
        }

        Shape* temp = head;
        int index = 0;
        while (temp) {
            cout << index << ": ";
            temp->draw();
            temp = temp->getNext();
            index++;
        }
    }

    ~GraphicEditor() {
        while (head) {
            Shape* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

// main 함수
int main() {
    GraphicEditor editor;
    int command;

    cout << "그래픽 에디터입니다." << endl;

    while (true) {
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> command;

        switch (command) {
        case 1:
            editor.insertShape();
            break;
        case 2:
            editor.deleteShape();
            break;
        case 3:
            editor.showShapes();
            break;
        case 4:
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            cout << "잘못된 명령입니다." << endl;
        }
    }
}