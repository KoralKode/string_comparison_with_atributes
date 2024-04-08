/*Условие задачи:
Вводится две строки, первая-строка с которой надо сравнивать вторую, которую надо обработать.
Вторая строка-последовательность символов и команд.
Есть 4 команды:
<delete> Удаление символа после текущей позиции курсора.
<bspace> Удаление символа перед текущей позицией курсора.
<left> Курсор перемещается влево на один символ.
<right> Курсор перемещается вправо на один символ.
Вывести Yes если получились одинаковые строки, No если нет.
Пример 1:
Ввод:
hellochild
helto<left><bspace>l<delete>ochilds<bspace>
Вывод: Yes
Пример 2:
Ввод:
programming
programming<left><left><right><delete>
Вывод:
No

*/
#include <iostream>
using namespace std;

int main() {
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int st = 0;
    int en = 0;
    string actual;
    auto it = actual.begin();
    bool f = true;

    for (int i = 0;i < s2.size();++i) {
        if (s2[i] == '<') {
            if (s2[i + 1] == 'l' && actual.size() > 0) {
                if (f == true) {

                }
                else if (it == actual.begin()) {
                    f = true;
                }
                else {
                    --it;
                }
                i += 5;
            }
            else if (s2[i + 1] == 'r' && actual.size() > 0) {
                if (f == true) {
                    it = actual.begin();
                    f = false;
                }
                else if (it == actual.end() - 1) {

                }
                else if (it == actual.end()) {
                    it = actual.end() - 1;
                }
                else {
                    ++it;
                }
                i += 6;
            }
            else if (s2[i + 1] == 'b' && actual.size() > 0) {
                if (f == true) {

                }
                else if (actual.size() == 1) {
                    actual.erase(actual.begin());
                    it = actual.begin();
                    f = true;
                }
                else if (it == actual.begin()) {
                    actual.erase(actual.begin());
                    f = true;
                    it = actual.begin();
                }
                else {
                    auto it2 = it - 1;
                    actual.erase(it);
                    it = it2;
                }
                i += 7;
            }
            else if (actual.size() > 0) {
                if (it == actual.end() - 1 && f != true) {

                }
                else if (f == true) {
                    actual.erase(actual.begin());
                    it = actual.begin();
                }
                else {
                    actual.erase(it + 1);
                }
                i += 7;
            }



        }
        else {
            if (actual.size() == 0) {
                actual.push_back(s2[i]);
                f = false;
                it = actual.begin();
            }
            else if (it == actual.end() - 1) {
                actual.push_back(s2[i]);
                ++it;
            }
            else if (f == true) {
                actual.insert(actual.begin(), s2[i]);
                f = false;
                it = actual.begin();
            }
            else if (it == actual.end()) {
                actual.push_back(s2[i]);
                it = actual.end() - 1;
            }
            else {
                actual.insert(it + 1, s2[i]);
                ++it;
            }
        }
    }
    if (s1 == actual) { cout << "Yes"; }
    else {
        cout << "No";
    }
}