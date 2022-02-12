# Tetris game in C lang
Creating a Tetris game in c language.

✨읽어주시면 감사합니다.✨

안녕하세요 :) 

🚀 저 혼자만의 생각으로 코드를 작성했기에 조금이라도 제 코드를 이해하는데 도움이 될 개요를 source 별로 간략히 작성했습니다.

:one: 간략하게 제 소스파일과 헤더파일에 대해서 설명 할 것입니다.![:octocat:](https://github.githubassets.com/images/icons/emoji/octocat.png ":octocat:")

 :two: 제가 테트리스 만들면서, 기초적으로 알면 도움이 될 만한 정보? 또한 블로그에 정리했는데 참고 링크 남기겠습니다!!

## 소스파일과 헤더파일

- [x] ysh_tetris_blocks.h 
- [ ] tetris_blocks.c
	>테트리스의 7가지 블록 종류와, 각각의 블록에 따른 4가지 회전 상태를 4차원 배열로 작성했습니다.
	>
	> ' **0** '은 빈 공간을 나타내고, ' **2** ' 는 블록을 나타냅니다.
	---
- [x] ysh_tetris_consoleCursor.h 
- [ ] Tetris_consoleCursor.c
	>테트리스에서 사용되는 가장 중요하면서도 기초적인 커서 다루는 함수들이 정의, 구현되어 있습니다.  
	- **Tetris_consoleCursor.c** 소스파일에 각각의 함수에 대한 **코드 리뷰** 했습니다.
	- 추가적으로 커서 관련 예?를 다루는 글을 작성했습니다. **GotoXY()**는 콘솔창의 특정한 위치에 특정한 **모양**으로 출력을 할 수 있도록 해주는 함수입니다. 이 함수를 모른다면 콘솔창에서 특정한 위치에 문자열을 출력할 수 없습니다.(GotoXY() 사용하지 않으면, 그냥 왼쪽에서 오른쪽으로, 또는 줄바꿈만 출력 되는 문자열을 보게 됩니다.) **중요✨✨✨✨✨**
		- addr : https://dev-with-precious-dreams.tistory.com/entry/C%EC%96%B8%EC%96%B4-GotoXY%ED%95%A8%EC%88%98%EB%A1%9C-%EC%BD%98%EC%86%94-%EC%B0%BD%EC%9D%98-%EC%BB%A4%EC%84%9C%EB%A5%BC-%EB%82%B4-%EB%A7%88%EC%9D%8C%EB%8C%80%EB%A1%9C-%EC%9D%B4%EB%8F%99%ED%95%98%EA%B8%B0
	---
- [x] ysh_tetris_AddBlockColor.h
- [ ] tetris_AddBlockColor.c
	> 이 source는 처음 테트리스를 초기 구현했을 때 background가 너무 밋밋하고 블록색도 화려하지 않았습니다. **멋있고, 화려하고 감성있게 꾸며보자!!** 는 마음가짐으로 지금 현재 출력되는 블록 색상 변경, 블록이 bottom에 쌓였을 때 특정 블록 색상 유지 등의 경우에 대한 메서드를 만들었습니다. 
	> 
	> 함수들 전반적으로 블록에 색을 추가합니다. 
	- 블록을 알록달록하게 표현하고 싶어서 위의 source를 구현했습니다. (덕분에 코드가 길어졌다는 점.. skip해도 좋습니다.)
	---
- [x] ysh_tetris_controller.h
- [ ] tetris_controller.c
	> 테트리스가 작동되는데 있어 **✨가장 중요한 함수들✨**이 구현되어 있습니다!! 특히 tetris_process()나 deleteLine() ,IsCollision() 등등 한개라도 없으면 돌아가지 않습니다...(아닌가?)
	- **✨ysh_tetris_controller.h✨** 헤더 파일에 controller.h와 함수들에 대한 **✨✨**주석 설명**✨✨**이 있습니다. 
	- 사용자의 키보드 눌림이 발생했을 경우 tetris_process( )의 _kbhit() , _getch()를 통해 특정 방향키를 얻을 수 있습니다. 
		- _kbhit() _getch() 함수 사용법을 모르신다면.. 예시를 제가 작성했습니다. 따라하면 (~~뭐야 이거 별거아니잖~~) 이해하실 수 있을 겁니다!!
		-  addr : https://dev-with-precious-dreams.tistory.com/entry/C%EC%96%B8%EC%96%B4-kbhitgetch%ED%95%A8%EC%88%98%EB%A5%BC-%EC%82%AC%EC%9A%A9%ED%95%B4-%EC%BD%98%EC%86%94%EC%B0%BD%EC%97%90%EC%84%9C-%EB%B0%A9%ED%96%A5%ED%82%A4-%EC%82%AC%EC%9A%A9%ED%95%98%EB%8A%94-%EB%B0%A9%EB%B2%95
	---
- [x] ysh_tetris_screen.h
- [ ] tetris_Screen.c
> 이 소스파일에서 테트리스 **background** 에 대한 메서드 들을 정의하고 구현 했습니다. 
> 
> 제가 미적 감각이 없어서 (확실히 UI는 외주를..) 최대한 열심히 도안을 짜고 심심하지 않게 인터넷에서 돌고래 그림도 찾아서 백그라운드에 추가후 출력을 해봤는데. 뭔가.. 어렵습니다. 뭔가 어설픈데.. 그래도 없는 것보단 나쁘지 않은 것 같습니다.
> 
> 초반 도입부, 인트로는 스타워즈를 상상하며 최대한 느낌있게 tetris를 출력했습니다. (그아레있는 네모는 테트리스를 표현한 것인데.) 
- [x] ysh_tetris_main.c
> 마지막으로 메인함수입니다. 이곳에 PlaySound()메서드를 선언했는데, 음악 파일이 깨져서 .. 위의 함수 안에 매개변수 BGM을 추가적으로 자신이 다운받은 경로를 (~~쿼우팅으로.. 죄송합니다 스위프트 공부중이라~~) 문자열로 지정하면 배경음 과 같은 소리가 나옵니다!!!

진짜 아무것도 몰랐는데 (코딩에 ㅋ 자도 몰랐는데,,) 결국 만들었습니다. 자신감도 생겼고, 프로그래밍에 대한 흥미도 생겼습니다. 

 여러분도 화이팅!!


테트리스 작성하면서 느낀 점.
https://www.youtube.com/watch?v=_piLfRpZlLg&t=59s
