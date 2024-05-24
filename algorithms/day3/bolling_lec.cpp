#include <iostream>
#include <vector>

// exceptions
// 1. alphabet
// 2. 0 ~ 10
int main() {
  //     1. 10점, 두 번째 기회 x
  //     2. 0~9점, 두 번째 기회 o
  //     3. ^ 9번 반복
  //     4. 1+2번째에서 10점, 3번째 o

  //     5. spare, strike
  //     spare - 두번 쳐서 10        - 이번 frame 점수 = (다음 frame의 첫번째
  //     기회의 점수 + 10점) strike - 첫번째 기회로 10   - 이번 frame 점수 =
  //     (다음 frame의 전체 점수 + 10점)
  //                                 - 연속 스트라이크 최대 2회 누적. (연속으로
  //                                 쳐도 2frame 전 점수 계산함 = 10 + 10 +
  //                                 1회차)
  //     -> 바로 점수 계산 x

  // 숫자 입력 받아서
  std::vector<std::vector<int>> frame;
  std::vector<int> frame10;

  std::vector<int> scores;

  frame.push_back({0, 0});
  scores.push_back(0);

  std::string input;
  int score;

  // 1~9frame
  for (size_t i = 1; i < 10; ++i) {
    frame.push_back({0, 0});

    while (true) {
      std::cout << i << " frame 1st bowl: ";
      std::getline(std::cin, input);

      try {
        score = std::stoi(input);

        if (score < 0 || score > 10)
          throw std::runtime_error("invalid input");

        break;
      } catch (std::exception &e) {
        std::cout << "failure due to : " << e.what() << std::endl;
      }
    }
    frame[i][0] = score;

    // 이전 기록 스페어 점수 계산
    if (i > 1 && frame[i - 1][0] != 10 &&
        frame[i - 1][0] + frame[i - 1][1] == 10) {
      scores[i - 1] = scores[i - 2] + 10 + frame[i][0];
      std::cout << "==========================" << std::endl;
      std::cout << i - 1 << " frame score: " << scores[i - 1] << std::endl;
      std::cout << "==========================" << std::endl;
    }

    // 전전 기록 스트라이크 + 전 기록 스트라이크 점수 계산
    if (i > 2 && frame[i - 2][0] == 10 && frame[i - 1][0] == 10) {
      scores[i - 2] = scores[i - 3] + 10 + 10 + frame[i][0];
      std::cout << "==========================" << std::endl;
      std::cout << i - 2 << " frame score: " << scores[i - 2] << std::endl;
      std::cout << "==========================" << std::endl;
    }

    // 지금 스트라이크 -> 2번째 x
    // 아니면 2번째 o
    if (frame[i][0] != 10) {
      std::cout << i << " frame 2nd bowl: ";
      std::getline(std::cin, input);

      score = std::stoi(input);
      frame[i][1] = score;

      if (i > 1 && frame[i - 1][0] == 10) {
        scores[i - 1] = scores[i - 2] + 10 + frame[i][0] + frame[i][1];
        std::cout << "==========================" << std::endl;
        std::cout << i - 1 << " frame score: " << scores[i - 1] << std::endl;
        std::cout << "==========================" << std::endl;
      }

      if (frame[i][0] + frame[i][1] < 10) {
        scores[i] = scores[i - 1] + frame[i][0] + frame[i][1];
        std::cout << "==========================" << std::endl;
        std::cout << i << " frame score: " << scores[i] << std::endl;
        std::cout << "==========================" << std::endl;
      }
    }
  }

  // 10th frame
  std::cout << "10 frame 1st bowl: ";
  std::getline(std::cin, input);

  score = std::stoi(input);
  frame10.push_back(score);

  // 9번째 스페어
  if (frame[9][0] != 10 && frame[9][0] + frame[9][1] == 10) {
    scores[9] = scores[8] + 10 + frame[10][0];
    std::cout << "==========================" << std::endl;
    std::cout << "9 frame score: " << scores[9] << std::endl;
    std::cout << "==========================" << std::endl;
  }

  // 8번째+9번째 스트라이크
  if (frame[8][0] == 10 && frame[9][0] == 10) {
    scores[8] = scores[7] + 10 + 10 + frame[10][0];
    std::cout << "==========================" << std::endl;
    std::cout << "8 frame score: " << scores[8] << std::endl;
    std::cout << "==========================" << std::endl;
  }

  std::cout << "10 frame 2nd bowl: ";
  std::getline(std::cin, input);

  score = std::stoi(input);
  frame10.push_back(score);

  // 9번째 스트라이크
  if (frame[9][0] == 10) {
    scores[9] = scores[8] + 10 + frame10[0] + frame10[1];
    std::cout << "==========================" << std::endl;
    std::cout << "9 frame score: " << scores[9] << std::endl;
    std::cout << "==========================" << std::endl;
  }

  // 첫번째 + 두번째 >= 10    -> 3회차
  if (frame10[0] + frame10[1] >= 10) {
    std::cout << "10 frame 3rd bowl: ";
    std::getline(std::cin, input);

    score = std::stoi(input);
    frame10.push_back(score);

    scores[10] = scores[9] + frame10[0] + frame10[1] + frame10[2];
    std::cout << "==========================" << std::endl;
    std::cout << "10 frame score: " << scores[10] << std::endl;
    std::cout << "==========================" << std::endl;
  } else {
    scores[10] = scores[9] + frame10[0] + frame10[1];
    std::cout << "==========================" << std::endl;
    std::cout << "10 frame score: " << scores[10] << std::endl;
    std::cout << "==========================" << std::endl;
  }
}
