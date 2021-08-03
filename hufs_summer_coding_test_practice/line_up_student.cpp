#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Student {
public:
	int number;
	int height;
	int weight;

	Student(int number, int height, int weight) {
		this->number = number;
		this->height = height;
		this->weight = weight;
	}
};

bool cmp(const Student& a, const Student& b) {
	if (a.height != b.height) {
		return a.height > b.height;
	}
	else {
		if (a.weight != b.weight) {
			return a.weight > b.weight;
		}
		else {
			return a.number > b.number;
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<Student> students;

	for (int i = 0; i < n; i++) {
		int height, weight;
		cin >> height >> weight;
		students.push_back(Student(i+1, height, weight));
	}

	sort(students.begin(), students.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << students[i].height << " ";
		cout << students[i].weight << " ";
		cout << students[i].number << endl;
	}

}