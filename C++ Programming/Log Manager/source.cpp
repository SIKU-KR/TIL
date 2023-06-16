#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include<sstream>
#include<iomanip>
using namespace std;
using namespace std::chrono;

class FileManager {
private:
	ofstream logfile;
public:
	FileManager(const string& filename) {
	/*
		filename 이름의 로그파일을 app 형식으로 연다
		app 형식 : 모든 출력을 파일의 끝에 추가
		파일이 없는경우 새로 만들어서 연다
	*/
		logfile.open(filename, ios::app);
		if (!logfile.is_open()) {
			ofstream newFile(filename);
			newFile.close();
			logfile.open(filename, ios::app);
		}
	}
	void saveLog(const string& log) {
		logfile << log << endl;
	}

	~FileManager() {
		logfile.close();
	}
};

class LogManager {
private:
	FileManager& fileManager;
	bool screen; // default : true
	bool file; // default : true
public:
	LogManager(FileManager& fm);
	void setOption();
	string getCurrentTimeAsString();
	void createLog(const string& logType, const string& sourceFile, const int& sourceLine);
};

// 생성자
LogManager::LogManager(FileManager& fm) : fileManager(fm), file(true), screen(true) {}

void LogManager::setOption() {
	int num;
	try {
		cout << "로그 출력 옵션을 선택하세요" << endl
			<< "1. 화면출력 o 파일출력 o" << endl
			<< "2. 화면출력 o 파일출력 x" << endl
			<< "3. 화면출력 x 파일출력 o" << endl
			<< "원하는 번호를 입력하세요 : ";
		cin >> num;
		if (num < 1 || num > 3) {
			throw num;
		}
	}
	catch(int e){
		cout << "입력값 오류!" << endl;
		exit(0);
	}
	switch (num) {
	case(1):
		screen = true;
		file = true;
		break;
	case(2):
		screen = true;
		file = false;
		break;
	case(3):
		screen = false;
		file = true;
		break;
	}
}

string LogManager::getCurrentTimeAsString() {
	// 현재 시간 가져오기
	auto now = system_clock::now();
	auto timePoint = time_point_cast<milliseconds>(now);
	// 형식 지정
	auto currentTime = system_clock::to_time_t(timePoint);
	tm* localTime = localtime(&currentTime);
	// 밀리초 계산
	auto ms = duration_cast<milliseconds>(timePoint.time_since_epoch()) % 1000;
	// 출력 문자열 생성
	ostringstream oss;
	oss << put_time(localTime, "%Y%m%d%H%M%S") << setw(3) << setfill('0') << ms.count();
	return oss.str();
}

void LogManager::createLog(const string& logType, const string& sourceFile, const int& sourceLine) {
	// sourceLine 형변환
	string Line = to_string(sourceLine);
	// YYYYMMDDHHMMSSSSS 형식으로 가져오기
	string currentTime = getCurrentTimeAsString();
	// log 만들기
	string log = currentTime + ":[" + sourceFile + "][" + Line + "] - " + logType;
	// 파일에 저장
	if (file) {
		fileManager.saveLog(log);
	}
	// 화면에 출력
	if (screen) {
		cout << log << endl;
	}
}

string getCurrentDateAsString() {
	// 현재 시간 가져오기
	auto now = system_clock::now();
	auto timePoint = time_point_cast<seconds>(now);
	// 형식 지정
	auto currentTime = system_clock::to_time_t(timePoint);
	tm* localTime = localtime(&currentTime);
	// 출력 문자열 생성
	ostringstream oss;
	oss << put_time(localTime, "%Y%m%d");
	return oss.str();
}

int main() {
	// currentDate 변수에 YYYYMMDD.txt 로 저장
	string filename = getCurrentDateAsString() + ".txt";

	// FileManager 불러오기, YYYYMMDD.txt 열기
	FileManager fm(filename);

	// LogManager 불러오기
	LogManager lm(fm);

	// 현재 파일명 출력
	cout << "현재 읽어진 파일명은 " << filename << "입니다." << endl;

	// 로그 출력옵션 세팅
	lm.setOption();

	// 어떤 로그를 출력할지? (반복)
	bool loopkey = true;
	int num;
	while(loopkey) {
		try {
			cout << endl << "어떤 log를 출력하시겠습니까?" << endl
				<< "1. Error Log" << endl
				<< "2. Warning Log" << endl
				<< "3. Event Log" << endl
				<< "4. Debug Log" << endl
				<< "5. 프로그램 종료" << endl
				<< "원하는 번호를 입력하세요 : ";
			cin >> num;
			if (num < 1 || num > 5) {
				throw num;
			}
		}
		catch (int e) {
			cout << "입력값 오류!" << endl;
			exit(0);
		}
		switch (num) {
		case 1:
			lm.createLog("error", __FILE__, __LINE__);
			break;
		case 2:
			lm.createLog("warning", __FILE__, __LINE__);
			break;
		case 3:
			lm.createLog("event", __FILE__, __LINE__);
			break;
		case 4:
			lm.createLog("debug", __FILE__, __LINE__);
			break;
		case 5:
			cout << "종료합니다..." << endl;
			loopkey = false;
			break;
		}
	}
	return 0;
}