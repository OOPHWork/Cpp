#include <iostream>
using namespace std;

class Dept {
    int size;
    int scores[10];
public:
    Dept(int size) {
        this->size = size;
    }

    int getSize() const {
        return size;
    }

    void read() {
        cout << "10개 점수 입력>> ";
        for(int i = 0; i < size; i++) {
            cin >> scores[i];
        }
    }

    bool isOver60(int index) const {
        return scores[index] >= 60;
    }
};

int countPass(const Dept& dept) {
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if(dept.isOver60(i)) count++;
    }
    return count;
}

int main() {
    Dept com(10);
    com.read();
    int n = countPass(com);
    cout << "60점 이상은 " << n << "명";
    return 0;
}
