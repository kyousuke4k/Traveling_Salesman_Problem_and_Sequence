#include<iostream> 
#include<tuple>
#include<vector>
#define DEBUG_FLAG 1
/*グローバル変数群*/
std::vector<int> tribonacci = { 1,2,4,7,13,24,44,81,149,274,504,927,1705,
3136,5768,10609,19513,35890,66012,121415,223317,
410744,755476,1389537,2555757,4700770,8646064,
15902591,29249425,53798080,98950096,181997601,
334745777,615693474,1132436852 };


class load {
private:
	std::tuple<int, int, int> sequence;//タプル
public:
	void set_Origin(int a) { std::get<0>(sequence)=a; }
	void set_Goto(int b) { std::get<1>(sequence) = b; }
	void set_sequence(int s) { std::get<2>(sequence) = s; }
};

class city {
private:
	bool priority_flag = false;
	int city_number;
	int n;//都市が所持する道の数
public:
	void set_Cnum(int num) { this->city_number = num; }
	void set_Priority() { priority_flag = true; }
	int city_call() { return city_number; }
};

class traveling {
private:
	city *a;//動的配列
	load *b;//動的配列
	int n;//都市数
	void setting_city();//都市初期化
	void setting_load();//道初期化
public:
	traveling(int n);
	~traveling();
};


//コンストラクタ
traveling::traveling(int n) {
	this->n = n;
	setting_city();
}
//デストラクタ
traveling::~traveling() {
	if (a != NULL)
		free(a);
	if (b != NULL)
		free(b);
}

void traveling::setting_city() {
	a = new city[n];
	for (int i = 0; i < n; i++) {
		a[i].set_Cnum(i);//都市ナンバーセット
		if (i <= 0)a[i].set_Priority();//初めだけ優先フラグセット
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