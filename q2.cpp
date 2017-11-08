//3���� ��ȸ
//0������ 10��
//S ^1  D ^2  T ^3
//* ��Ÿ�� # ������
//* �������� ���ݲ� *2 ù��°�� ù��°�� ��ø ����
//# ���ݲ��� -2��
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
	while (ins && ins.peek() != '\n')//������ ���������� �ݺ��մϴ�.
	{
		if (isdigit(ins.peek()))//������ ���
		{
			ins >> num;
			st.push(num);
		}
		else if (strchr("SDT*#", ins.peek()) != NULL)//�����ڰ� ������ ���
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