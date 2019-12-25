class Solution {
public:
	string solveEquation(string equation) {
		int flag1 = 1,flag2=1;
		int x = 0, num = 0;
		

		while (equation.length()!=0) {
			int pos = min(min(equation.find('-',1), equation.find('+',1)), equation.find('=',1));
			if (pos<equation.length() && equation[pos] == '=') {
				flag1 = -1;
				equation.replace(pos, 1, "+");
			}
			if (pos == string::npos) pos = equation.length();
			string str = equation.substr(0, pos);
			if (equation.substr(0, pos).find('x') != string::npos) {
				
				if (pos <= 2) { 
					if (equation[0] == 'x') x += 1;
					else if (equation[0] == '+' || equation[0] == '-') {
						int temp = atoi((equation.substr(0, pos - 1) + "1").c_str());
						x += atoi((equation.substr(0, pos - 1) + "1").c_str()) * flag2;
					}
					else 
						x+=atoi((equation.substr(0, pos - 1)).c_str()) * flag2;
				}
				else x += atoi((equation.substr(0, pos-1)).c_str()) * flag2;
			}
			else {
				num += atoi(equation.substr(0, pos).c_str()) * flag2;
			}
			flag2 = flag1;
			equation = equation.substr(pos);
		}
		if (x == 0 && num == 0) return "Infinite solutions";
		else if (x == 0 && num != 0) return "No solution";
		else return "x=" + to_string(num / x * -1);

	}
};