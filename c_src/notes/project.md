# Project

## Project Process

## Github repo

라이센스 -> 코드의 활용 범위 지정

Apache 2.0 -> 마음대로 쓰되, 출처는 명확하게

## 프로젝트 기술서

역할 나누기 -> 모듈 별로 (몇 개씩)

- 기술 스택
- 참고 서적
- 서식 제공

## 문서화

파일, 클래스, 구조체, 변수 의 사용방식

- 타인이 읽고, 프로그램을 쉽게 활용할 수 있도록

### doxygen

주석을 문법에 맞게 작성하면, 문서화 자동

#### graphviz

class,functions 등을 그래프로 만들어준다

`sudo apt install doxygen graphviz doxygen-gui gt5`
`unset GTK_PATH`

프로젝트 설정, HTML 페이지 구성

# .vscode

c_cpp_properties.json -> intelisence가
launch -> 옵션 파일
tasks -> 디버깅 설정

gcc -> 소스 공개 의무화
clang -> 딱히?

# CMakelists.txt

Set minimum version
Set project name
Add executable

# Release

Source -> Build -> bin -> release

## 알리기

### 패키지 매니저

- 실행파일 재배치
- 실행가능 폴더 : /usr/local/{bin, include, src}
  pip, npm, apt

### make install

bin -> 실행가능폴더

# 실행흐름 (thread)

main -> menu -> play
main -> menu -> exit

빠르게 실행

모니터 -> 1초에 60번 갱신 -> 60Hz

## interrupt

SIGNAL

키보드 입력
scanf -> 무조건 block

`ch = getch()`

실시간으로 키보드 입력을 받을 수 있는 기능
