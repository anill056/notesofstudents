
// ANIL AKSU 230103020

#include <iostream>

using namespace std;

int main() {
	const int nmof_students = 5; // öğrenci sayısı
	const int nmof_grades = 2; // öğrenci başına düşen notlar
	double sum; // toplam değeri



	float** studentgrades = new float* [nmof_students]; //öğrenci sayısına göre not sayısınin çift boyutlu dizisi Dinamik bellek yönetimi ile (5x2)

	for (int i = 0; i < nmof_students; i++) {
		studentgrades[i] = new float[nmof_grades]; // Her öğrenci için 2 notluk yer ayırıyoruz.
	}

	double averages[nmof_students];


	// notları kullanıcıdan alıyoruz.
	for (int i = 0; i < nmof_students; i++) {
		cout << "Enter grades for student " << (i + 1) << ":" << endl;
		for (int j = 0; j < nmof_grades; j++) {
			while (true) {
				cout << "Note " << (j + 1) << ": ";
				cin >> studentgrades[i][j];
				//geçersiz giriş kontrolü
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input! please enter a numeric grade." << endl; //sayı dışında değer girilirse bu hatayı veriyor.
				}
				else {
					break;

				}
			}
		}
	}

	// ekrana notları yazdırır ve ortalamalarını hesapla.
	cout << "\nEntered notes and averages\n" << endl;
	for (int i = 0; i < nmof_students; i++) {
		sum = 0;
		cout << "Student " << (i + 1) << ": ";
		for (int j = 0; j < nmof_grades; j++) {
			cout << "Note " << (j + 1) << ": " << studentgrades[i][j] << " ";
			sum += studentgrades[i][j];
		}

		averages[i] = sum / nmof_grades; // ortalama hesaplama
		cout << "| Average: " << averages[i] << endl;
	}


	for (int i = 0; i < nmof_students; i++) {
		delete[] studentgrades[i]; //her öğrenci için ayrılan belleği temizleme.
	}

	delete[] studentgrades; //ana diziyi temizleme.

	return 0;
}