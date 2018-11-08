# Python Plugin In C++
## 목적

c++ 프로그램에서 파이썬 플러그인을 사용해 c++에서 생성된 객체들을 제어한다.

## 파일 설명

- main.cpp :  
  프로그램의 메인 함수가 들어있는 원시 소스. 파이썬 인터프리터를 호출한다.
- animal.h / animal.cpp :  
  예제로 사용될 클래스인 Animal 이 포함되어 있는 원시 소스.
- animal.i :  
  swig를 통해 파이썬에서 사용될 animal 모듈을 생성하기 위한 파일.
- Makefile :  
  컴파일 옵션에 대한 정보가 들어있는 파일.
- plugin.py :  
  메인함수에서 직접적으로 가져오는 모듈. 하위 디렉토리인 plugins 안의 모든 .py 모듈들을 가져온다.

## 테스트 환경

Windows10  
Python 3.6 , 3.7  
SWIG 3.0  
MingW  

## 동작 설명

1. 파이썬에서 조작될 Animal 객체 생성. 객체 변수 m_speed의 초기값은 10.
2. 파이썬 실행. 파이썬 animal 모듈의 정적 전역 변수 g_animal을 1.에서 생성된 객체의 포인터로 설정.
3. plugin.py 가져오기. plugin.py는 plugins 디렉토리에 있는 모든 .py를 실행.
4. plugins/animal_speed.py에서 객체의 변수(m_speed)의 값 변경 (10 -> 20).

파이썬 모듈 호출이 끝나고 난 뒤, 1. 에서 생성된 객체의 m_speed 값을 출력해보면 20이 나오는 것을 확인할 수 있다.
