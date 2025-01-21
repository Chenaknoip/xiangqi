#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int nor[12][11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 21, 22, 23, 24, 25, 24, 23, 22, 21,0,
                   0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0,
                   0, 0 , 27, 0 , 0 , 0 , 0 , 0 , 27, 0 ,0,
                   0, 26, 0 , 26, 0 , 26, 0 , 26, 0 , 26,0,
                   0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0,
                   0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0,
                   0, 16, 0 , 16, 0 , 16, 0 , 16, 0 , 16,0,
                   0, 0 , 17, 0 , 0 , 0 , 0 , 0 , 17, 0 ,0,
                   0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0,
                   0, 11, 12, 13, 14, 15, 14, 13, 12, 11,0,
                   0,0,0,0,0,0,0,0,0,0,0
                  };
int dsk[12][11];
void output(int x, int y) {
	if (dsk[x][y] == 0) {
		if (x == 2 && y == 5) cout << "╳ ";
		else if (x == 9 && y == 5) cout << "╳ ";
		else if (x == 1) {
			if (y == 1) cout << "└ ";
			else if (y == 9) cout << "┌ ";
			else cout << "├ ";
		} else if (x == 10) {
			if (y == 1) cout << "┘ ";
			else if (y == 9) cout << "┐ ";
			else cout << "┤ ";
		} else if (y == 1) cout << "┴ ";
		else if (y == 9) cout << "┬ ";
		else if (x == 5) cout << "┤ ";
		else if (x == 6) cout << "├ ";
		else cout << "┼ ";
	} else {
		if (dsk[x][y] / 10 == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		string s;
		int tmp = dsk[x][y] % 10;
		if (tmp == 1) s = "車";
		if (tmp == 2) s = "马";
		if (tmp == 3) s = "象";
		if (tmp == 4) s = "士";
		if (tmp == 5) s = (dsk[x][y] / 10 == 1) ? "帅" : "将";
		if (tmp == 6) s = (dsk[x][y] / 10 == 1) ? "卒" : "兵";
		if (tmp == 7) s = "炮";
		cout << s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}
bool ok(int fang, int x, int y, int nx, int ny) {
	if (x == -1 && y == 0 && nx == 0 && ny == 0) return true;
	if (x < 1 || x > 10 || y < 1 || y > 9 || nx < 1 || nx > 10 || ny < 1 || ny > 9) return false;
	if (dsk[x][y] == 0) return false;
	if (dsk[x][y] / 10 == dsk[nx][ny] / 10) return false;
	int tmp = dsk[x][y];
	if (tmp / 10 != fang) return false;
	tmp %= 10;
	if (tmp == 1) {
		if (x != nx && y != ny) return false;
		if (x == nx) {
			for (int yy = min(y, ny) + 1; yy < max(y, ny); yy++) if (dsk[x][yy] != 0) return false;
			return true;
		} else {
			for (int xx = min(x, nx) + 1; xx < max(x, nx); xx++) if (dsk[xx][y] != 0) return false;
			return true;
		}
	} else if (tmp == 2) {
		int dx = nx - x, dy = ny - y;
		int tx = abs(dx), ty = abs(dy);
		if (min(tx, ty) != 1 || max(tx, ty) != 2) return false; // bu ri
		if (tx == 2) {
			tx = (dx > 0) ? 1 : -1;
			ty = 0;
		} else {
			ty = (dy > 0) ? 1 : -1;
			tx = 0;
		}
		if (dsk[x + tx][y + ty] != 0) return false;
		return true;
	} else if (tmp == 3) {
		int dx = nx - x, dy = ny - y;
		int tx = abs(dx), ty = abs(dy);
		if (tx != 2 || ty != 2) return false; // bu tian
		tx = (dx > 0) ? 1 : -1, ty = (dy > 0) ? 1 : -1;
		if (dsk[x + tx][y + ty] != 0) return false;
		if (dsk[x][y] / 10 == 1) {
			if (nx < 6) return false;
		} else {
			if (nx > 5) return false;
		}
		return true;
	} else if (tmp == 4) {
		int dx = nx - x, dy = ny - y;
		int tx = abs(dx), ty = abs(dy);
		if (tx != 1 || ty != 1) return false; // bu ri
		if (ny < 4 || ny > 6) return false;
		if (x < 5) {
			return nx <= 3;
		} else {
			return nx >= 8;
		}
		return true;
	} else if (tmp == 5) {
		if (dsk[nx][ny] % 10 == 5) {
			if (y != ny) return false;
			for (int i = min(x, nx) + 1; i < max(x, nx); i++) {
				if (dsk[i][y] != 0) return false;
			}
			return true;
		} else {
			int dx = nx - x, dy = ny - y;
			int tx = abs(dx), ty = abs(dy);
			if (min(tx, ty) != 0 || max(tx, ty) != 1) return false;
			if (ny < 4 || ny > 6) return false;
			if (x < 5) {
				return nx <= 3;
			} else {
				return nx >= 8;
			}
		}
	} else if (tmp == 6) {
		if (dsk[x][y] / 10 == 1) {
			if (nx < 6) { // ctr
				int dx = nx - x, dy = ny - y;
				return dx == -1 && dy == 0 || dx == 0 && abs(dy) == 1;
			} else {
				int dx = nx - x, dy = ny - y;
				return dx == -1 && dy == 0;
			}
		} else {
			if (nx > 5) { // ctr
				int dx = nx - x, dy = ny - y;
				return dx == 1 && dy == 0 || dx == 0 && abs(dy) == 1;
			} else {
				int dx = nx - x, dy = ny - y;
				return dx == 1 && dy == 0;
			}
		}
	} else { // tmp == 7
		if (x != nx && y != ny) return false;
		if (x == nx) {
			int cnt = 0;
			if (y < ny) {
				for (int yy = y + 1; yy <= ny; yy++)  {
					if (dsk[x][yy] != 0) cnt++;
				}
			} else {
				for (int yy = y - 1; yy >= ny; yy--)  {
					if (dsk[x][yy] != 0) cnt++;
				}
			}
			if (cnt == 0) return true;
			else if (cnt == 2 && dsk[nx][ny] != 0) return true;
			else return false;
		} else {
			int cnt = 0;
			if (x < nx) {
				for (int xx = x + 1; xx <= nx; xx++)  {
					if (dsk[xx][y] != 0) cnt++;
				}
			} else {
				for (int xx = x - 1; xx >= nx; xx--)  {
					if (dsk[xx][y] != 0) cnt++;
				}
			}
			if (cnt == 0) return true;
			else if (cnt == 2 && dsk[nx][ny] != 0) return true;
			else return false;
		}
	}
	return true;
}
bool canmove(int x, int y, int nx, int ny) {
	if (dsk[x][y] == 0) return false;
	if (dsk[x][y] / 10 == dsk[nx][ny] / 10) return false;
	int tmp = dsk[x][y];
	tmp %= 10;
	if (tmp == 1) {
		if (x != nx && y != ny) return false;
		if (x == nx) {
			for (int yy = min(y, ny) + 1; yy < max(y, ny); yy++) if (dsk[x][yy] != 0) return false;
			return true;
		} else {
			for (int xx = min(x, nx) + 1; xx < max(x, nx); xx++) if (dsk[xx][y] != 0) return false;
			return true;
		}
	} else if (tmp == 2) {
		int dx = nx - x, dy = ny - y;
		int tx = abs(dx), ty = abs(dy);
		if (min(tx, ty) != 1 || max(tx, ty) != 2) return false; // bu ri
		if (tx == 2) {
			tx = (dx > 0) ? 1 : -1;
			ty = 0;
		} else {
			ty = (dy > 0) ? 1 : -1;
			tx = 0;
		}
		if (dsk[x + tx][y + ty] != 0) return false;
		return true;
	} else if (tmp == 3) {
		int dx = nx - x, dy = ny - y;
		int tx = abs(dx), ty = abs(dy);
		if (tx != 2 || ty != 2) return false; // bu tian
		tx = (dx > 0) ? 1 : -1, ty = (dy > 0) ? 1 : -1;
		if (dsk[x + tx][y + ty] != 0) return false;
		if (dsk[x][y] / 10 == 1) {
			if (nx < 6) return false;
		} else {
			if (nx > 5) return false;
		}
		return true;
	} else if (tmp == 4) {
		int dx = nx - x, dy = ny - y;
		int tx = abs(dx), ty = abs(dy);
		if (tx != 1 || ty != 1) return false; // bu ri
		if (ny < 4 || ny > 6) return false;
		if (x < 5) {
			return nx <= 3;
		} else {
			return nx >= 8;
		}
		return true;
	} else if (tmp == 5) {
		if (dsk[nx][ny] % 10 == 5) {
			if (y != ny) return false;
			for (int i = min(x, nx) + 1; i < max(x, nx); i++) {
				if (dsk[i][y] != 0) return false;
			}
			return true;
		} else {
			int dx = nx - x, dy = ny - y;
			int tx = abs(dx), ty = abs(dy);
			if (min(tx, ty) != 0 || max(tx, ty) != 1) return false;
			if (ny < 4 || ny > 6) return false;
			if (x < 5) {
				return nx <= 3;
			} else {
				return nx >= 8;
			}
		}
	} else if (tmp == 6) {
		if (dsk[x][y] / 10 == 1) {
			if (nx < 6) { // ctr
				int dx = nx - x, dy = ny - y;
				return dx == -1 && dy == 0 || dx == 0 && abs(dy) == 1;
			} else {
				int dx = nx - x, dy = ny - y;
				return dx == -1 && dy == 0;
			}
		} else {
			if (nx > 5) { // ctr
				int dx = nx - x, dy = ny - y;
				return dx == 1 && dy == 0 || dx == 0 && abs(dy) == 1;
			} else {
				int dx = nx - x, dy = ny - y;
				return dx == 1 && dy == 0;
			}
		}
	} else { // tmp == 7
		if (x != nx && y != ny) return false;
		if (x == nx) {
			int cnt = 0;
			if (y < ny) {
				for (int yy = y + 1; yy <= ny; yy++)  {
					if (dsk[x][yy] != 0) cnt++;
				}
			} else {
				for (int yy = y - 1; yy >= ny; yy--)  {
					if (dsk[x][yy] != 0) cnt++;
				}
			}
			if (cnt == 0) return true;
			else if (cnt == 2 && dsk[nx][ny] != 0) return true;
			else return false;
		} else {
			int cnt = 0;
			if (x < nx) {
				for (int xx = x + 1; xx <= nx; xx++)  {
					if (dsk[xx][y] != 0) cnt++;
				}
			} else {
				for (int xx = x - 1; xx >= nx; xx--)  {
					if (dsk[xx][y] != 0) cnt++;
				}
			}
			if (cnt == 0) return true;
			else if (cnt == 2 && dsk[nx][ny] != 0) return true;
			else return false;
		}
	}
	return true;
}
bool check(bool f) {
	int jx = 0, jy = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (dsk[i][j] == ((int)f + 1) * 10 + 5) {
				jx = i;
				jy = j;
				break;
			}
		}
		if (jx && jy) break;
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (canmove(i, j, jx, jy)) return true;
		}
	}
	return false;
}
int is_checkmated(bool f) {
	for (int x = 1; x <= 10; x++) {
		for (int y = 1; y <= 9; y++) {
			if (dsk[x][y] / 10 == f + 1) {
				for (int nx = 1; nx <= 10; nx++) {
					for (int ny = 1; ny <= 9; ny++) {
						if (canmove(x, y, nx, ny)) {
							int tmp = dsk[nx][ny];
							dsk[nx][ny] = dsk[x][y];
							dsk[x][y] = 0;
							if (!check(f)) {
								dsk[x][y] = dsk[nx][ny];
								dsk[nx][ny] = tmp;
								return false;
							}
							dsk[x][y] = dsk[nx][ny];
							dsk[nx][ny] = tmp;
						}
					}
				}
			}
		}
	}
	return (int)check(f) + 1;
}
bool done() {
	bool flag1 = false, flag2 = false;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (dsk[i][j] == 15) flag1 = true;
			if (dsk[i][j] == 25) flag2 = true;
		}
	}
	return !(flag1 && flag2);
}
void work() {
	bool fang = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			dsk[i][j] = nor[i][j];
		}
	}
	while (!done()) {
		if (is_checkmated(fang) == 2) {
			system("cls");
			cout << (fang ? "蓝" : "红") << "方被将死，";
			break;
		} else if (is_checkmated(fang) == 1) {
			system("cls");
			cout << (fang ? "蓝" : "红") << "方被困毙，";
			break;
		}
		system("cls");
		cout << "y\n";
		for (int i = 9; i >= 1; i--) {
			cout << i << " ";
			for (int j = 1; j <= 10; j++) {
				output(j, i);
			}
			putchar('\n');
		}
		cout << "  ";
		for (int i = 1; i <= 10; i++) {
			cout << i << " ";
		}
		cout << "x\n\n";
		int x, y, nx, ny;
		cout << "现在轮" << ((fang == 0) ? "红" : "蓝") << "走。\n";
		if (check(fang)) cout << ((fang == 0) ? "红" : "蓝") << "方正在被将军。\n";
		cout << "认输输入 -1 0 0 0。\n";
		cout << "(x1, y1) 表示棋子坐标，(x2, y2) 表示目标坐标。\n";
		cout << "输入坐标, x1 y1 x2 y2：";
		cin >> x >> y >> nx >> ny;
		while (!ok(fang + 1, x, y, nx, ny)) {
input:
			cout << "输入非法，重新输入：";
			cin >> x >> y >> nx >> ny;
		}
		if (x == -1) {
			system("cls");
			cout << (fang ? "蓝" : "红") << "方认输，";
			break;
		}
		int ss = dsk[x][y], yuan = dsk[nx][ny];
		dsk[x][y] = 0;
		dsk[nx][ny] = ss;
		if (check(fang)) {
			dsk[x][y] = ss;
			dsk[nx][ny] = yuan;
			goto input;
		}
		fang ^= 1;
	}
	cout << (fang ? "红" : "蓝") << "方胜！\n";
	cout << "y\n";
	for (int i = 9; i >= 1; i--) {
		cout << i << " ";
		for (int j = 1; j <= 10; j++) {
			output(j, i);
		}
		putchar('\n');
	}
	cout << "  ";
	for (int i = 1; i <= 10; i++) {
		cout << i << " ";
	}
	cout << "x\n\n";
	system("pause");
}
int main() {
	while (true) {
		system("cls");
		cout << "\t中    国    象    棋\t\n\n";
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 9; j++) {
				dsk[i][j] = nor[i][j];
			}
		}
		for (int i = 9; i >= 1; i--) {
			cout << "\t";
			for (int j = 1; j <= 10; j++) {
				output(j, i);
			}
			cout << "\t";
			putchar('\n');
		}
		cout << "\n";
		system("pause");
		work();
	}
	return 0;
}
