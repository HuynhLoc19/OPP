
#include <iostream>
#include <string>
using namespace std;

class XE
{
protected:
	string hoten;
	float sogio;
public:
	void Nhap_DL();
	void Xuat_DL();
};

//	Hàm nhập thông tin thuê xe
void XE::Nhap_DL()
{
	cin.ignore();
	cout << "\n+ Nhap ho ten nguoi thue: ";
	getline(cin, hoten);
	cout << "\n+ Nhap so gio thue: ";
	cin >> sogio;
}

// Hàm xuất thông tin thuê xe 
void XE::Xuat_DL()
{
	cout << "\n+ Ho ten nguoi thue xe: " << hoten;
	cout << "\n+ So gio thue xe: " << sogio;
}

// Xe đạp
class XEDAP : public XE
{
private:
public:
	float Tinh_Tien();
};

//	Hàm tính tiền thuê xe đạp (giờ đầu tiên là 10k, các giờ tiếp theo là 8k)
float XEDAP::Tinh_Tien()
{
	return (size_t)(10000 + (sogio - 1) * 8000);
}

// Xe may
class XEMAY : public XE
{
private:
	int loaixe;
	string bienso;
public:
	void Nhap_DL();
	void Xuat_DL();
	float Tinh_Tien();
	int Getter_LoaiXe()
	{
		return loaixe;
	}
};

//	 Hàm nhập thông tin thuê xe máy
void XEMAY::Nhap_DL()
{
	XE::Nhap_DL();
	cout << "\n+ Nhap loai xe (100cc or 250cc): ";
	cin >> loaixe;
	cin.ignore();
	cout << "\n+ Nhap bien so xe: ";
	getline(cin, bienso);
}

//	Hàm xuất thông tin xe máy: 
void XEMAY::Xuat_DL()
{
	XE::Xuat_DL();
	cout << "\n+ Loai xe thue: " << loaixe;
	cout << "\n+ Bien so xe: " << bienso << endl;
}

//	Hàm tính tiền thuê xe máy (Giờ đầu tiên, xe 1000cc là 150k, xe 250cc là 200k, những giờ tiếp theo cả hai loại xe là 100k))
float XEMAY::Tinh_Tien()
{
	if (loaixe == 100)
	{
		return (size_t)(150000 + (sogio - 1) * 100000);
	}
	else
	{
		return (size_t)(200000 + (sogio - 1) * 1000000);
	}
}

void menu(XEDAP ds_dap[], int m, XEMAY ds_may[], int n)
{
	int lc;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t============== QUAN LY THUE XE ==============";
		cout << "\n\t\t 1. Nhap thong tin thue xe.";
		cout << "\n\t\t 2. Xuat thong tin thue xe.";
		cout << "\n\t\t 3. Tinh tong tien cho thue xe.";
		cout << "\n\t\t 4. Ket thuc.";
		cout << "\n\t\t    ============== KET THUC ==============";

		cout << "\n Nhap lua chon: ";
		cin >> lc;
		if (lc == 1)
		{
			int luachon;
			while (true)
			{
				system("cls");
				cout << "\n\n\t\t============== NHAP THONG TIN THUE XE  ==============";
				cout << "\n\t\t 1. Nhap thong tin thue xe DAP.";
				cout << "\n\t\t 2. Nhap thong tin thue xe MAY.";
				cout << "\n\t\t 3. KET THUC.";
				cout << "\n\t\t      ============== KET THUC ==============";

				cout << "\n Nhap lua chon: ";
				cin >> luachon;
				if (luachon == 1)
				{
					XEDAP dap;
					cout << "\n\t\t NHAP THONG TIN THUE XE DAP." << endl;
					dap.Nhap_DL();
					ds_dap[m++] = dap;
				}
				else if (luachon == 2)
				{
					XEMAY may;
					cout << "\n\t\t NHAP THONG TIN THUE XE MAY." << endl;
					may.Nhap_DL();
					ds_may[n++] = may;
				}
				else
				{
					break;
				}
			}
		}
		else if (lc == 2)
		{
			int luachon;
			while (true)
			{
				system("cls");
				cout << "\n\n\t\t============== XUAT THONG TIN THUE XE  ==============";
				cout << "\n\t\t 1. Xuat thong tin thue xe DAP.";
				cout << "\n\t\t 2. Xuat thong tin thue xe MAY.";
				cout << "\n\t\t 3. KET THUC.";
				cout << "\n\t\t       ============== KET THUC ==============";

				cout << "\n Nhap lua chon: ";
				cin >> luachon;
				if (luachon == 1)
				{
					cout << "\n DANH SACH THUE XE DAP: ";
					for (int i = 0; i < m; i++)
					{
						cout << "\n\n\tNguoi thue " << i + 1 << ": ";
						ds_dap[i].Xuat_DL();
						cout << "+ Tien thue xe: " << (size_t)ds_dap[i].Tinh_Tien() << endl;
					}
					system("pause");
				}
				else if (luachon == 2)
				{
					cout << "\n DANH SACH THUE XE MAY: ";
					for (int i = 0; i < n; i++)
					{
						cout << "\n\n\tNguoi thue " << i + 1 << ": ";
						ds_may[i].Xuat_DL();
						cout << "+ Tien thue xe: " << (size_t)ds_may[i].Tinh_Tien() << endl;
					}
					system("pause");
				}
				else
				{
					break;
				}
			}
		}
		else if (lc == 3)
		{
			int luachon;
			while (true)
			{
				system("cls");
				cout << "\n\n\t\t============== TINH TIEN THUE XE  ==============";
				cout << "\n\t\t 1. Tinh tien thue tung XE DAP.";
				cout << "\n\t\t 2. Tinh tien thue tat ca XE DAP";
				cout << "\n\t\t 3. Tinh tien thue XE MAY loai 100cc";
				cout << "\n\t\t 4. Tinh tien thue XE MAY loai 250cc";
				cout << "\n\t\t 5. Tinh tien thue tat ca XE MAY";
				cout << "\n\t\t 6. KET THUC.";
				cout << "\n\t\t     ============== KET THUC ==============";

				cout << "\n Nhap lua chon: ";
				cin >> luachon;
				if (luachon == 1)
				{
					cout << "\n\t\t======== TIEN THUE TUNG XE DAP ========" << endl;
					for (int i = 0; i < m; i++)
					{
						cout << "  + Tien thue xe dap cua nguoi " << i + 1 << ": ";
						cout << (size_t)(ds_dap[i].Tinh_Tien()) << endl;
					}
					system("pause");
				}
				else if (luachon == 2)
				{
					cout << "\n\t\t======== TONG TIEN THUE TAT CA XE DAP ========" << endl;
					double S = 0;
					for (int i = 0; i < m; i++)
					{
						S += ds_dap[i].Tinh_Tien();
					}
					cout << "\n  =>=> Tong tien thue tat ca xe dap: " << (size_t)S << endl;
					system("pause");
				}
				else if (luachon == 3)
				{
					cout << "\n\t\t======== TONG TIEN THUE XE MAY LOAI 100CC ========" << endl;
					double S = 0;
					for (int i = 0; i < n; i++)
					{
						if (ds_may[i].Getter_LoaiXe() == 100)
						{
							S += ds_may[i].Tinh_Tien();
						}
					}
					cout << "\n  =>=> Tong tien thue xe may loai 100cc: " << (size_t)S << endl;
					system("pause");
				}
				else if (luachon == 4)
				{
					cout << "\n\t\t======== TONG TIEN THUE XE MAY LOAI 250CC ========" << endl;
					double S = 0;
					for (int i = 0; i < n; i++)
					{
						if (ds_may[i].Getter_LoaiXe() == 250)
						{
							S += ds_may[i].Tinh_Tien();
						}
					}
					cout << "\n  =>=> Tong tien thue xe may loai 250cc: " << (size_t)S << endl;
					system("pause");
				}
				else if (luachon == 5)
				{
					cout << "\n\t\t======== TONG TIEN THUE XE MAY ========" << endl;
					int S = 0;
					for (int j = 0; j < n; j++)
					{
						S += ds_may[j].Tinh_Tien();
					}
					cout << "\n  =>=> Tong tien thue xe may: " << (size_t)S << endl;
					system("pause");
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
}

int main()
{
	XEDAP ds_dap[10];
	int m = 0;
	XEMAY ds_may[10];
	int n = 0;
	menu(ds_dap, m, ds_may, n);
	cout<<"\nHuan Hoa Hong co lam tho moi co an."<<endl;
	cout<<"\n Khong lam ma doi co an thi an dau bua, an cam."<<endl;
	return 0;
}
