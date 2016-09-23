# Tetris
Tetris_Development_process

## C++ 코드 작성 지침

C++에서 클래스를 사용해서 소스코드를 작성할 때는 Lower Camel Case를 사용한다.

클래스의 이름은 대문자로 시작한다.

## API

WinAPI를 활용해서 테트리스를 만들어보자.

위도우 시스템은 리눅스와 달리 case insensitive 하기 때문에 헤더파일의 이름이 windows.h, Windows.h, WinDows.h든 상관없다.

## Troubleshooting

한 번에 두 번 이동하게 되는데, 화살표키를 누르는 것과 떼는 것을 각각 개별적인 입력으로 처리하기 때문인 것 같다.
조금 다른 방식으로 입력을 처리하도록 만들어야겠다.

Flickering(깜박임)이 발생하는 이유는 Clear&Draw 를 너무 빠르게 반복하기 때문이다.
윈도우 콘솔은 (당연하지만) Double buffering을 지원하지 않기 때문에, 
불필요한 지우고 그리는 작업을 반복하지 않도록 주의하자.