#include <iostream>

using namespace std;
/**
 * Khai bao bien
 */
struct sach //
{
    int ma_sach;  // Ma sach
    char ten[40]; // Ten sach
    float gia;    // Gia sach
};

int so_luong_sach = 0; // So luong sach trong thu vien
sach thu_vien[] = {};  // Mang cach sach co trong thu vien

// ---------------------------------------------------------
// a) Nhập danh sách gồm N cuốn sách
void nhap_sach()
{
    sach s;
    cout << "Nhap ma sach \n";
    cin >> s.ma_sach;
    cout << "Nhap ten sach \n";
    cin >> s.ten;
    cout << "Nhap gia \n";
    cin >> s.gia;
    thu_vien[so_luong_sach] = s;
    so_luong_sach++;
    cout << "Sach " << s.ten << " da luu vao thu vien \n";
}
// ---------------------------------------------------------
// b) Xuất danh sách các cuốn sách ra màn hình
void danh_sach()
{
    cout << "--------------- DANH SACH --------------- \n";
    cout << "--Ma---------Ten----------------Gia------ \n";
    for (int i = 0; i < so_luong_sach; i++)
    {
        cout << thu_vien[i].ma_sach << ". " << thu_vien[i].ten << ".  " << thu_vien[i].gia << " \n";
    }
    cout << "----------------------------------------- \n";
}

// ---------------------------------------------------------
// c) Tìm cuốn sách có mã là X (Làm theo 2 cách: tìm tuyến tính và tìm nhị phân)
// --------------------------tìm tuyến tính-----------------
void tim_sach_tuyen_tinh()
{
    int ma_sach_can_tim;
    cout << "--------------- TIM SACH --------------- \n";
    cout << "Nhap ma sach can tim \n";
    cin >> ma_sach_can_tim; // chua tim thay
    // Tim tuyen tinh
    bool tim_thay = false;
    for (int i = 0; i < so_luong_sach; i++)
    {
        if (ma_sach_can_tim == thu_vien[i].ma_sach)
        {
            tim_thay = true; // da tim thay
            cout << thu_vien[i].ma_sach << ".   " << thu_vien[i].ten << "    " << thu_vien[i].gia << " \n";
        }
    }

    // Thong bao khong tim thay sach
    if (!tim_thay)
    {
        cout << "Khong tim thay ma sach: " << ma_sach_can_tim << " \n";
    }
}

// -------------------------tìm nhị phân--------------------
void tim_sach_nhi_phan()
{
    int ma_sach_can_tim;
    cout << "--------------- TIM SACH --------------- \n";
    cout << "Nhap ma sach can tim \n";
    cin >> ma_sach_can_tim; // chua tim thay
}
// e) Xuất các cuốn sách có giá cao nhất (nếu có nhiều sách có giá cao nhất trùng nhau thì xuất hết ra màn hình).
void hien_thi_sach_gia_cao_nhat()
{
    cout << "----- SACH CO GIA CAO NHAT --------- \n";
    //
    sach sach_gia_cao_nhat = thu_vien[0];

    // Tim sach co gia cao nhat
    for (int i = 1; i < so_luong_sach; i++)
    {
        if (sach_gia_cao_nhat.gia < thu_vien[i].gia)
        {
            sach_gia_cao_nhat = thu_vien[i];
        }
    }

    // Hien thi danh sach co gia cao nhat
    for (int i = 1; i < so_luong_sach; i++)
    {
        if (sach_gia_cao_nhat.gia == thu_vien[i].gia)
        {
            cout << thu_vien[i].ma_sach << ".   " << thu_vien[i].ten << "    " << thu_vien[i].gia << "\n";
        }
    }
}
// Menu
void menu()
{
    cout << "CHUONG TRINH QUAN LY THU VIEN \n";
    cout << "1. Nhap Sach Vao Thu Vien\n";
    cout << "2. Danh Sach (" << so_luong_sach << ")\n";
    cout << "3. Tim Sach Trong Thu Vien (Tim Tuyen Tinh) \n";
    cout << "4. Tim Sach Trong Thu Vien (Tim Nhi Phan) \n";
    cout << "5. Tim Sach Gia Cao Trong Thu Vien\n";
    cout << "6. Thoat Chuong Trinh\n";
}

// Chuong trinh chinh
// MAIN
int main()
{

    bool chuong_trinh = true;
    while (chuong_trinh)
    {
        int tuy_chon;
        menu();
        cin >> tuy_chon;

        switch (tuy_chon)
        {
        case 1:
            nhap_sach();
            break;
        case 2:
            danh_sach();
            break;
        case 3:
            tim_sach_tuyen_tinh();
            break;
        case 4:
            tim_sach_tuyen_tinh();
            break;
        case 5:
            hien_thi_sach_gia_cao_nhat();
            break;
        case 6:
            chuong_trinh = false;
            break;
        default:
            cout << "Nhap 1 so tuy chon vao menu tren. \n";
            break;
        }
    }
    cout << "Thoat chuong trinh \n";

    return 0;
}
