/*
 * stack - 주식가격
 *
 * 짝 지어진?
 *
 * 실제로 사용할 수 있다는 사실을 알고, 연습할 것
 *
 * queue - 기능개발
 *
 * sort - greater template function
 *
 * for - 반복의 횟수가 정해져 있을 때
 * while - 반복의 횟수가 유동적일 때
 * */
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> tst_queue(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;

  // why you should use this?
  size_t size = progresses.size();
  std::queue<int> q;

  for (size_t i = 0; i < size; ++i)
    q.push(i);

  while (!q.empty()) {
    // what's the purpose?
    int cnt = 0;
    for (size_t i = 0; i < size; ++i)
      progresses[i] += speeds[i];

    // if (progresses[0] >= 100) {
    if (progresses[q.front()] >= 100) {
      while (progresses[cnt] >= 100) {
        q.pop();
        cnt++;
      }

      answer.push_back(cnt);
      cnt = 0;
    }
  }

  return answer;
}

int solution(vector<int> priorities, int location) {
  int answer = 0;
  std::queue<int> q;

  size_t size = priorities.size();

  for (size_t i = 0; i < size; ++i)
    q.push(i);

  int mx = *max_element(priorities.begin(), priorities.end());

  sort(priorities.begin(), priorities.end(), greater<int>());

  // max_element();

  return answer;
}
