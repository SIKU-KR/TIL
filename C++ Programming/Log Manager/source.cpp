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
		filename �̸��� �α������� app �������� ����
		app ���� : ��� ����� ������ ���� �߰�
		������ ���°�� ���� ���� ����
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

// ������
LogManager::LogManager(FileManager& fm) : fileManager(fm), file(true), screen(true) {}

void LogManager::setOption() {
	int num;
	try {
		cout << "�α� ��� �ɼ��� �����ϼ���" << endl
			<< "1. ȭ����� o ������� o" << endl
			<< "2. ȭ����� o ������� x" << endl
			<< "3. ȭ����� x ������� o" << endl
			<< "���ϴ� ��ȣ�� �Է��ϼ��� : ";
		cin >> num;
		if (num < 1 || num > 3) {
			throw num;
		}
	}
	catch(int e){
		cout << "�Է°� ����!" << endl;
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
	// ���� �ð� ��������
	auto now = system_clock::now();
	auto timePoint = time_point_cast<milliseconds>(now);
	// ���� ����
	auto currentTime = system_clock::to_time_t(timePoint);
	tm* localTime = localtime(&currentTime);
	// �и��� ���
	auto ms = duration_cast<milliseconds>(timePoint.time_since_epoch()) % 1000;
	// ��� ���ڿ� ����
	ostringstream oss;
	oss << put_time(localTime, "%Y%m%d%H%M%S") << setw(3) << setfill('0') << ms.count();
	return oss.str();
}

void LogManager::createLog(const string& logType, const string& sourceFile, const int& sourceLine) {
	// sourceLine ����ȯ
	string Line = to_string(sourceLine);
	// YYYYMMDDHHMMSSSSS �������� ��������
	string currentTime = getCurrentTimeAsString();
	// log �����
	string log = currentTime + ":[" + sourceFile + "][" + Line + "] - " + logType;
	// ���Ͽ� ����
	if (file) {
		fileManager.saveLog(log);
	}
	// ȭ�鿡 ���
	if (screen) {
		cout << log << endl;
	}
}

string getCurrentDateAsString() {
	// ���� �ð� ��������
	auto now = system_clock::now();
	auto timePoint = time_point_cast<seconds>(now);
	// ���� ����
	auto currentTime = system_clock::to_time_t(timePoint);
	tm* localTime = localtime(&currentTime);
	// ��� ���ڿ� ����
	ostringstream oss;
	oss << put_time(localTime, "%Y%m%d");
	return oss.str();
}

int main() {
	// currentDate ������ YYYYMMDD.txt �� ����
	string filename = getCurrentDateAsString() + ".txt";

	// FileManager �ҷ�����, YYYYMMDD.txt ����
	FileManager fm(filename);

	// LogManager �ҷ�����
	LogManager lm(fm);

	// ���� ���ϸ� ���
	cout << "���� �о��� ���ϸ��� " << filename << "�Դϴ�." << endl;

	// �α� ��¿ɼ� ����
	lm.setOption();

	// � �α׸� �������? (�ݺ�)
	bool loopkey = true;
	int num;
	while(loopkey) {
		try {
			cout << endl << "� log�� ����Ͻðڽ��ϱ�?" << endl
				<< "1. Error Log" << endl
				<< "2. Warning Log" << endl
				<< "3. Event Log" << endl
				<< "4. Debug Log" << endl
				<< "5. ���α׷� ����" << endl
				<< "���ϴ� ��ȣ�� �Է��ϼ��� : ";
			cin >> num;
			if (num < 1 || num > 5) {
				throw num;
			}
		}
		catch (int e) {
			cout << "�Է°� ����!" << endl;
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
			cout << "�����մϴ�..." << endl;
			loopkey = false;
			break;
		}
	}
	return 0;
}