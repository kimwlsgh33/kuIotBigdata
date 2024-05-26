#include <iostream>
#include <vector>
// 1. 10점, 두번째 기회 x
// 2. 0~9점, 두번째 기회 o
// 3. ^ 9번 반복
// 4. 1+2 번째에서 10점  3번째 o
// 5. spare, strike

// spare - 두번 쳐서 10
// 이번 회차 점수 = 다음 회차의 첫번쨰 기회의 점수 + 10점

// strike - 첫번쨰 기회로 10
// 이번 회차 점수 = 다음 회차의 전체 점수 + 10점

// 1frame = 2 ball
int main() {
  std::cout << "게임시작" << std::endl;

  // > > : to avoid compiler error
  std::vector<std::vector<int>> frame;
  std::vector<int> frame10;

  std::vector<int> scores;

  // 빈데이터 추가 (반복문 1 부터 시작)
  frame.push_back({0, 0});
  scores.push_back(0);

  std::string input;
  int score;

  int ball1, ball2;
  int bonus = 0;

  for (size_t i = 1; i < 10; ++i) {
    frame.push_back({0, 0});
    // std::cout << i + 1 << " 번째 게임 입니다" << std::endl;
    std::cout << i << " 번째 게임 입니다" << std::endl;
    while (true) {
      std::cout << i << "프레임, 1번째: ";
      std::getline(std::cin, input);

      try {
        score = std::stoi(input);
        break;
      } catch (std::exception &e) {
        std::cout << "failure due to: " << e.what() << std::endl;
      }
    }

    frame[i][0] = score;

    if (score == 10) {
      std::cout << "strike!" << std::endl;
      if (i == 9)
        bonus += 2;
    }

    while (true) {
      std::cout << i + 1 << "프레임, 2번째: ";
      std::getline(std::cin, input);

      try {
        score = std::stoi(input);
        break;
      } catch (std::exception &e) {
        std::cout << "failure due to: " << e.what() << std::endl;
      }
    }

    frame[i][1] = score;

    if (score == 10) {
      std::cout << "strike!" << std::endl;
      if (i == 9)
        bonus += 2;
    } else if (frame[i][0] + frame[i][1] == 10) {
      std::cout << "spare~" << std::endl;
      if (i == 9)
        ++bonus;
    }

    if (bonus) {
      for (int j = 0; j < bonus; ++j) {
        std::cout << "보너스 프레임! : ";
        std::getline(std::cin, input);

        try {
          score = std::stoi(input);
          break;
        } catch (std::exception &e) {
          std::cout << "failure due to: " << e.what() << std::endl;
        }

        frame[i][j + 2] = score;
      }

      bonus = 0;
    }
  }
}
