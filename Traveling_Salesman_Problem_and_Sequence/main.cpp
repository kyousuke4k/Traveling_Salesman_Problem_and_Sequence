#include<iostream> 
#include<tuple>
#include<vector>
#define DEBUG_FLAG 1
/*�O���[�o���ϐ��Q*/
std::vector<int> tribonacci = { 1,2,4,7,13,24,44,81,149,274,504,927,1705,
3136,5768,10609,19513,35890,66012,121415,223317,
410744,755476,1389537,2555757,4700770,8646064,
15902591,29249425,53798080,98950096,181997601,
334745777,615693474,1132436852 };


class load {
private:
	std::tuple<int, int, int> sequence;//�^�v��
public:
	void set_Origin(int a) { std::get<0>(sequence)=a; }
	void set_Goto(int b) { std::get<1>(sequence) = b; }
	void set_sequence(int s) { std::get<2>(sequence) = s; }
};

class city {
private:
	bool priority_flag = false;
	int city_number;
	int n;//�s�s���������铹�̐�
public:
	void set_Cnum(int num) { this->city_number = num; }
	void set_Priority() { priority_flag = true; }
	int city_call() { return city_number; }
};

class traveling {
private:
	city *a;//���I�z��
	load *b;//���I�z��
	int n;//�s�s��
	void setting_city();//�s�s������
	void setting_load();//��������
public:
	traveling(int n);
	~traveling();
};


//�R���X�g���N�^
traveling::traveling(int n) {
	this->n = n;
	setting_city();
}
//�f�X�g���N�^
traveling::~traveling() {
	if (a != NULL)
		free(a);
	if (b != NULL)
		free(b);
}

void traveling::setting_city() {
	a = new city[n];
	for (int i = 0; i < n; i++) {
		a[i].set_Cnum(i);//�s�s�i���o�[�Z�b�g
		if (i <= 0)a[i].set_Priority();//���߂����D��t���O�Z�b�g
	}
}

void traveling::setting_load() {
	b = new load[(n*(n - 1) / 2)];
	//first
	for (int i = 0; i < n - 1; i++) {
		b[i].set_Origin(a[0].city_call());
		b[i].set_Goto(a[i + 1].city_call());
	}
}
int main() {

	if (DEBUG_FLAG) {

	}

	return 0;
}