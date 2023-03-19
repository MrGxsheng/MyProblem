#include <bits/stdc++.h>
using namespace std;


//保留字
const string KeyWord[12] = { "main","int","char","if","else","for","while","return","void","STRING","ID","INT" };   //这个还可以有很多东西加，这里只是简单模拟而已，感兴趣的可以自己多加



int syn;  //单词种别码
string  token;       //单词自身字符串

int sum;  //INT整型里的码内值

int i = 0;  

int tag = 1;     //后面判断STRING字符的 


void showAll();     //输入部分单词符号所对应的种别码（可自行扩展）

bool IsLetter(char ch);   //判断是否为字母

bool IsDigit(char ch);   //判断是否为数字

void scan(string s);     //扫描



int main()
{
	showAll();
	string a="";
	cout << "\n欢迎来到Gassing的词法分析器，请输入字符串(以‘#’作为结束标志)：" << endl;
	getline(cin,a);
	

	
	cout<<"\n输出二元组（种别码，token或sum）："<<endl;


	do
	{
		scan(a);
		switch (syn)   //最后判断一波syn
		{
		case -1:
			cout << "error：无结束符或存在非法字符" << endl;
			syn = 0;
			break;
		case -2:      //遇到空格跳过
			break;
		default:
			if(syn!=0)
				cout << "( " << syn << "," << token << " )" << endl;
		}

	} while (syn!=0);
		

	
}

void showAll()    //展示部分单词符号所对应的种别码（可自行扩展）
{
	cout << 1 << endl;
	cout << "---------- 符号表---------------------- " << endl;

	cout << "符号\t种别码" << "\t" << "符号\t种别码" << endl;
	cout << "main" << '\t' << '1' << '\t' << "/" << '\t' << "25" << endl;
	cout << "int" << '\t' << '2' << '\t' << "(" << '\t' << "26" << endl;
	cout << "char" << '\t' << '3' << '\t' << ")" << '\t' << "27" << endl;
	cout << "if" << '\t' << '4' << '\t' << "[" << '\t' << "28" << endl;
	cout << "else" << '\t' << '5' << '\t' << "]" << '\t' << "29" << endl;
	cout << "for" << '\t' << '6' << '\t' << "{" << '\t' << "30" << endl;
	cout << "while" << '\t' << '7' << '\t' << "}" << '\t' << "31" << endl;
	cout << "return" << '\t' << '8' << '\t' << "," << '\t' << "32" << endl;
	cout << "void" << '\t' << '9' << '\t' << ":" << '\t' << "33" << endl;
	cout << "STRING" << '\t' << "50" << '\t' << ";" << '\t' << "34" << endl;
	cout << "ID" << '\t' << "10" << '\t' << ">" << '\t' << "35" << endl;
	cout << "INT" << '\t' << "20" << '\t' << "<" << '\t' << "36" << endl;
	cout << "=" << '\t' << "21" << '\t' << ">=" << '\t' << "37" << endl;
	cout << "+" << '\t' << "22" << '\t' << "<=" << '\t' << "38" << endl;
	cout << "-" << '\t' << "23" << '\t' << "==" << '\t' << "39" << endl;
	cout << "*" << '\t' << "24" << '\t' << "!=" << '\t' << "40" << endl;

	cout << "---------------------------------------" << endl;
	cout << "@author(Gassing)" << endl;
}


bool IsLetter(char ch)  //判断是否为字母
{
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		return true;
	else
		return false;

}

bool IsDigit(char ch)  //判断是否为数字
{
	if (ch >= '0'&&ch <= '9')
		return true;
	else
		return false;

}


void scan(string s)    //扫描
{
	if (s[i] == ' ')
	{
		syn = -2;
		i++;
	}
	else
	{
		token = "";   //清空当前字符串

		   //  1.判断字符是否为数字
		if (IsDigit(s[i]))
		{
			token = ""; //清空当前字符串
			sum = 0;
			while (IsDigit(s[i])) {
				sum = sum * 10 + (s[i] - '0');
				i++;  //字符位置++
				syn = 20;   //INT种别码为20
			}
			token += to_string(sum);     //骚操作，直接转化字符串
		}


		// 2.字符为字符串，表现为字母开头衔接任意个数字或字母
		else if (IsLetter(s[i]))
		{

			token = ""; //清空当前字符串
			while (IsDigit(s[i]) || IsLetter(s[i])) {
					token += s[i];   //加入token字符串
					i++;
			}
			

			

			//s[i] = '\0';  //刚刚上面最后i++了所以补充
			syn = 10;  // 如果是标识符，种别码为10

			//如果是关键字，则用for循环将token与keyword比较找对应的种别码
			for (int j = 0; j < 12; j++)
			{
				if (token == KeyWord[j])    //如果都是string类型，可以直接=相比较，若相等则返回1，否则为0
				{
					syn = j + 1;   //种别码从1开始所以要加1
					break;
				}
			}
		}

		//3. 判断为符号
		else {
			token = ""; //清空当前字符串
			switch (s[i]) {
			case'=':
				syn = 21;
				i++;
				token = "=";
				if (s[i] == '=') {
					syn = 39;
					i++;
					token = "==";
				}
				break;

			case'+':
				syn = 22;
				i++;
				token = "+";
				break;

			case'-':
				syn = 23;
				i++;
				token = "-";
				break;

			case'*':
				syn = 24;
				i++;
				token = "*";
				break;

			case'/':
				syn = 25;
				i++;
				token = "/";
				break;

			case'(':
				syn = 26;
				i++;
				token = "(";
				break;

			case')':
				syn = 27;
				i++;
				token = ")";
				break;

			case'[':
				syn = 28;
				i++;
				token = "[";
				break;

			case']':
				syn = 29;
				i++;
				token = "]";
				break;

			case'{':
				syn = 30;
				i++;
				token = "{";
				break;

			case'}':
				syn = 31;
				i++;
				token = "}";
				break;

			case',':
				syn = 32;
				i++;
				token = ",";
				break;

			case':':
				syn = 33;
				i++;
				token = ":";
				break;

			case';':
				syn = 34;
				i++;
				token = ";";
				break;

			case'>':
				syn = 35;
				i++;
				token = ">";
				if (s[i] == '=')
				{
					syn = 37;
					i++;
					token = ">=";
				}
				break;

			case'<':
				syn = 36;
				i++;
				token = "<";
				if (s[i] == '=')
				{
					syn = 38;
					i++;
					token = "<=";
				}
				break;

			case'!':
				syn = -1;
				i++;
				if (s[i] == '=')
				{
					syn = 40;
					i++;
					token = "!=";
				}
				break;

			case '"':
				syn = -1;
				token += s[i];
				i++;
				while (s[i] != '"')
				{
					if (s[i] == '#')
					{
						tag = 0;
						break;
					}
					else
					{
						token += s[i];
						i++;
					}
				}
			     if (tag)
				{
					token += s[i];
					i++;
					syn = 50;
					break;
				}
				else
				{
					syn = -1;
					cout << "双引号只存在一个，非法输入 " << endl;
					break;
				}

				

			case '#': //结束
				syn = 0;
				cout << "\n#结束" << endl;
				break;

			default:
				syn = -1;
				break;
			}
		}
	}
	        
		
}
