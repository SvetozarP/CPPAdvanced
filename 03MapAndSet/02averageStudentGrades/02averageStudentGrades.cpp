#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int numberOfStudents;
	cin >> numberOfStudents;
	
	map<string, vector<double>> studentGrades;

	while (numberOfStudents-- > 0) {
		string studentName;
		double grade;
		cin >> studentName >> grade;
		studentGrades[studentName].push_back(grade);
	}

	for (const auto& [studentName, grades] : studentGrades) {

		double sum = 0.0;

		double average = sum / grades.size();
		cout << fixed << setprecision(2);
		cout << studentName << " -> ";
		
		for (double grade : grades) {
			cout << grade << " ";
			sum += grade;
		}
		
		average = sum / grades.size();

		cout << "(avg: " << average << ")" << endl;
	}
	return 0;
}
