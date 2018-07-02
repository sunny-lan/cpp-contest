#ifdef DMOJ

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

vector<int> dishes[MAXN];
vector<int> people[MAXN];
vector<int> activeDishes[MAXN];

bool visited[MAXN];
bool visDish[MAXN];
int cnt[MAXN];

void ex(int code = -1) {
	if (code != -1)
		printf("every man for himself! \n", code);
	else
		printf("every man for himself!\n");
	exit(0);
}

int main() {
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int d; scan(d);
		for (int j = 0; j < d; j++) {
			int x; scan(x);
			x--;
			dishes[i].push_back(x);
			people[x].push_back(i);
			cnt[x]++;
		}
	}
	vector<pair<bool, int>> cust;
	for (int i = 0; i < n; i++) {
		for (int dish : dishes[i]) {
			if (people[dish].size() > 1) {
				activeDishes[i].push_back(dish);
			}
		}

		if (activeDishes[i].size() > 2)
			ex();

		if (activeDishes[i].size() == 1 && dishes[i].size() > 1)
			cust.push_back({ false, i });
	}

	for (int i = 0; i < n; i++) {
		int custard = 0;
		for (int person : people[i]) {
			if (activeDishes[person].size() == 2)
				custard++;
		}

		if (custard == 1)
			cust.push_back({ true, i });
	}

	vector<int> resppl;
	vector<int> resdish;
	for (auto est : cust) {
		int st = est.second;
		if (visited[st])continue;
		int currPerson = -1;
		int currDish = -1;
		int pivotDish = -1;
		if (est.first) {
			pivotDish = currDish = st;
			goto eee;
		}
		else {
			currPerson = st;
		}
		while (true) {
			resppl.push_back(currPerson);
			visited[currPerson] = true;

			//find active dish of curr person
			pivotDish = -1;
			for (int dish : activeDishes[currPerson])
				if (dish != currDish)
					pivotDish = dish;

			//add all simple dishes of curr person
			for (int dish : dishes[currPerson])
				if (dish != pivotDish && dish != currDish) {
					resdish.push_back(dish);
					if (visDish[dish])ex();
					visDish[dish] = true;
				}

			//no next person/dish
			if (pivotDish == -1)break;

		eee:

			//add pivot dish between curr person and next person
			resdish.push_back(pivotDish);
			if (visDish[pivotDish])ex();
			visDish[pivotDish] = true;

			//find next person white adding simple people of pivot dish
			int nxtPerson = -1;
			for (int person : people[pivotDish])
				if (person != currPerson) {
					if (dishes[person].size() > 1)
						nxtPerson = person;
					else
						resppl.push_back(person),
						visited[person] = true;
				}

			//no next person
			if (nxtPerson == -1)break;

			currPerson = nxtPerson;
			currDish = pivotDish;
		}
	}

	//add all simple people
	for (int i = 0; i < n; i++)if (!visited[i])
	{
		if (dishes[i].size() < 2 )continue;
		resppl.push_back(i);
			for (int dish : dishes[i])
				resdish.push_back(dish),
				visDish[dish] = true;
	}

	//add all simple dishes
	for (int i = 0; i < n; i++)if (!visDish[i]) {
		if (people[i].size() < 2)continue;
		resdish.push_back(i);
			for (int person : people[i])
				resppl.push_back(person);
	}

	//add all pairs
	for (int i = 0; i < n; i++)  {
		if(people[i].size()==1)
			if(dishes[people[i][0]][0]==i)
				resdish.push_back(i),
				resppl.push_back(people[i][0]);
	}

	//add all isolated stuff
	for (int i = 0; i < n; i++)
	{
		if (people[i].size() == 0 )
			resdish.push_back(i);
		if (dishes[i].size() == 0)
			resppl.push_back(i);
	}

	if (resdish.size() != resppl.size() || resdish.size() != n)
		ex(1);

	for (int i : resppl)
		printf("%d ", i + 1);
	printf("\n");
	for (int i : resdish)
		printf("%d ", i + 1);
	printf("\n");
	cin >> n;
}