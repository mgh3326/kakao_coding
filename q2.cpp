//3번의 기회
//0점부터 10점
//S ^1  D ^2  T ^3
//* 스타상 # 아차상
//* 이전꺼랑 지금꺼 *2 첫번째는 첫번째만 중첩 가능
//# 지금꺼만 -2배
//1S2D*3T 1^1 * 2 + 2^2 * 2 + 3^3
//2+8+27=37
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int infixPostfix(std::istream& ins)
{
	int answer = 0;
	int num;//?
	char symbol;//?
	std::stack<int> st;
	while (ins && ins.peek() != '\n')//문장이 끝날때까지 반복합니다.
	{
		if (isdigit(ins.peek()))//숫자인 경우
		{
			ins >> num;
			st.push(num);
		}
		else if (strchr("SDT*#", ins.peek()) != NULL)//연산자가 나오는 경우
		{
			ins >> symbol;
			switch (symbol)
			{
			//case 'S' :break;
			case 'D' :num = st.top();
				//pow(num, 2);
				st.pop();
				st.push(pow(num,2));
				break;
			case 'T':num = st.top();
				//pow(num, 3);
				st.pop();
				st.push(pow(num,3));
				break;
			case '*':num = st.top();
				st.pop();
				//num=num * 2;
				if (!st.empty()) {
					int num2 = st.top();
					st.pop();
					st.push(num2*2);
				}
				st.push(num*2);
				break;
			case '#': num = st.top();
				st.pop();
				st.push(-num);
				break;

			default: break;
			}
		}
	}
	while (!st.empty())
	{
		 answer=answer+st.top();
		st.pop();
	}
	return answer;
}
int main(void) {
	
		std::cout << infixPostfix(std::cin) << std::endl;

}