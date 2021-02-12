#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
#include <vector>
using namespace std;
enum Type { GAMER, NONEGAMER };

struct Info
{
	Info(int a, string p, int t, Type ty) :age(a),preference(p), timeWaste(t), type(ty) {}
	int age;
	string preference;
	int timeWaste;
	Type type;
};


class Person
{
protected:
	string m_name;
	int m_age;

public:
	Person(string n, int a) : m_name(n), m_age(a) {}
	Info virtual GetInfo() = 0;
};


class Student : public Person
{
protected:
	string m_college,
		m_program;
	int semester;

public:
	Student(string n, int a, string c, string p, int s) : Person(n, a),
	m_college(c), m_program(p), semester(s) { }
};

class NonGameingStudent : public Student
{
private:
	string m_stream;
	double m_hourWaste;

public:
	NonGameingStudent(string n, int a, string c, string p, int s, string st, double h) :
	Student(n,a,c,p,s), m_stream(st), m_hourWaste(h) {}
	Info GetInfo() override { return Info(m_age, m_stream, m_hourWaste, NONEGAMER); }

	
};

class GamingStudent : public Student
{
	string m_game;
	double m_hourWaste;

public:
	GamingStudent(string n, int a, string c, string p, int s, string g, double h) :
	Student(n, a, c, p, s), m_game(g), m_hourWaste(h) {}
	Info GetInfo() override { return Info(m_age, m_game, m_hourWaste, GAMER); };
};

class Survey
{
private:
	vector<Person*> m_pParticipants;
	
	void Generate(int n);

public:
	Survey(int n) { Generate(n); };
	string Process();
	void Clean();
};






#endif
