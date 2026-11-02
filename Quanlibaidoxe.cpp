// Quanlibaidoxe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Xe {
private:
    int maXe;
    string loaiXe;
    int gioVao;
    int thoiGianDo;
    double phiDoXe;
    bool dangChiemCho;

public:
    Xe() {
        maXe = 0;
        loaiXe = "Bicycle";
        gioVao = 0;
        thoiGianDo = 1;
        phiDoXe = 0;
        dangChiemCho = false;
    }

    Xe(int ma, const string& loai, int gio, int thoiLuong) {
        maXe = ma;
        loaiXe = chuanHoaLoaiXe(loai);
        gioVao = gio;
        thoiGianDo = thoiLuong;
        phiDoXe = 0;
        dangChiemCho = true;
        tinhPhiDoXe();
    }

    int layMaXe() const { return maXe; }
    string layLoaiXe() const { return loaiXe; }
    int layGioVao() const { return gioVao; }
    int layThoiGianDo() const { return thoiGianDo; }
    double layPhiDoXe() const { return phiDoXe; }
    bool layDangChiemCho() const { return dangChiemCho; }

    void ganMaXe(int ma) { maXe = ma; }
    void ganLoaiXe(const string& loai) {
        if (laLoaiXeHopLe(loai))
            loaiXe = chuanHoaLoaiXe(loai);
    }
    void ganGioVao(int gio) {
        if (gio >= 0 && gio <= 23)
            gioVao = gio;
    }
    void ganThoiLuongDo(int thoiLuong) {
        if (thoiLuong >= 1 && thoiLuong <= 23)
            thoiGianDo = thoiLuong;
    }
    void ganPhiDoXe(double phi) { phiDoXe = phi; }
    void ganDangChiemCho(bool trangThai) {
        dangChiemCho = trangThai;
    }

    static string chuanHoaLoaiXe(const string& loai) {
        string s = loai;
        for (int i = 0; i < (int)s.length(); i++)
            s[i] = tolower((unsigned char)s[i]);

        if (s == "car") return "Car";
        if (s == "motorcycle") return "Motorcycle";
        if (s == "bicycle") return "Bicycle";
        return "";
    }

    static bool laLoaiXeHopLe(const string& loai) {
        return chuanHoaLoaiXe(loai) != "";
    }

    void tinhPhiDoXe() {
        double donGia = 0;

        if (loaiXe == "Car") donGia = 6;
        if (loaiXe == "Motorcycle") donGia = 4;
        if (loaiXe == "Bicycle") donGia = 2;

        phiDoXe = 0;

        for (int i = 0; i < thoiGianDo; i++) {
            int gio = (gioVao + i) % 24;

            if (i < 2) {
                if ((gio >= 6 && gio < 10) ||
                    (gio >= 15 && gio < 19))
                    phiDoXe += donGia * 1.3;
                else
                    phiDoXe += donGia * 0.95;
            }
            else {
                phiDoXe += donGia * 0.9;
            }
        }
    }

    void hienThi() const {
        cout << "Ma xe: " << maXe << endl;
        cout << "Loai xe: " << loaiXe << endl;
        cout << "Gio vao: " << gioVao << endl;
        cout << "Thoi gian do: " << thoiGianDo << endl;
        cout << "Phi do xe: " << phiDoXe << endl;
    }
};

class BaiDoXe {
private:
    int maBai;
    char kichThuoc;
    Xe xe1, xe2, xe3;
    bool coXe1, coXe2, coXe3;

public:
    BaiDoXe() {
        maBai = 0;
        kichThuoc = 'S';
        coXe1 = coXe2 = coXe3 = false;
    }

    BaiDoXe(int ma, char size) {
        maBai = ma;
        kichThuoc = size;
        coXe1 = coXe2 = coXe3 = false;
    }

    int layMaBai() const { return maBai; }
    char layKichThuoc() const { return kichThuoc; }

    int sucChua() const {
        if (kichThuoc == 'S') return 1;
        if (kichThuoc == 'M') return 2;
        return 3;
    }

    int soLuongXe() const {
        return coXe1 + coXe2 + coXe3;
    }

    bool coMaXe(int ma) const {
        if (coXe1 && xe1.layMaXe() == ma) return true;
        if (coXe2 && xe2.layMaXe() == ma) return true;
        if (coXe3 && xe3.layMaXe() == ma) return true;
        return false;
    }

    bool themXe(const Xe& xe) {
        if (!coXe1) {
            xe1 = xe;
            coXe1 = true;
            return true;
        }
        if (sucChua() >= 2 && !coXe2) {
            xe2 = xe;
            coXe2 = true;
            return true;
        }
        if (sucChua() >= 3 && !coXe3) {
            xe3 = xe;
            coXe3 = true;
            return true;
        }
        return false;
    }

    bool xoaXe(int ma) {
        if (coXe1 && xe1.layMaXe() == ma) {
            coXe1 = false;
            return true;
        }
        if (coXe2 && xe2.layMaXe() == ma) {
            coXe2 = false;
            return true;
        }
        if (coXe3 && xe3.layMaXe() == ma) {
            coXe3 = false;
            return true;
        }
        return false;
    }

    void hienThiThongTinBai() const {
        cout << "Ma bai: " << maBai << endl;
        cout << "Kich thuoc: " << kichThuoc << endl;
        cout << "So xe: " << soLuongXe() << "/" << sucChua() << endl;
    }

    void hienThiXe() const {
        hienThiThongTinBai();
        if (coXe1) xe1.hienThi();
        if (coXe2) xe2.hienThi();
        if (coXe3) xe3.hienThi();
    }

    void lietKeTheoLoai(const string& loai) const {
        if (coXe1 && xe1.layLoaiXe() == loai) xe1.hienThi();
        if (coXe2 && xe2.layLoaiXe() == loai) xe2.hienThi();
        if (coXe3 && xe3.layLoaiXe() == loai) xe3.hienThi();
    }

    double tongPhi(const string& loai) const {
        double tong = 0;
        if (coXe1 && xe1.layLoaiXe() == loai)
            tong += xe1.layPhiDoXe();
        if (coXe2 && xe2.layLoaiXe() == loai)
            tong += xe2.layPhiDoXe();
        if (coXe3 && xe3.layLoaiXe() == loai)
            tong += xe3.layPhiDoXe();
        return tong;
    }

    int demLoai(const string& loai) const {
        int dem = 0;
        if (coXe1 && xe1.layLoaiXe() == loai) dem++;
        if (coXe2 && xe2.layLoaiXe() == loai) dem++;
        if (coXe3 && xe3.layLoaiXe() == loai) dem++;
        return dem;
    }
};

class HeThong {
private:
    BaiDoXe bai1, bai2, bai3;
    bool coBai1, coBai2, coBai3;

public:
    HeThong() {
        coBai1 = coBai2 = coBai3 = false;
    }

    bool trungMaBai(int ma) {
        return (coBai1 && bai1.layMaBai() == ma) ||
            (coBai2 && bai2.layMaBai() == ma) ||
            (coBai3 && bai3.layMaBai() == ma);
    }

    bool trungMaXe(int ma) {
        return (coBai1 && bai1.coMaXe(ma)) ||
            (coBai2 && bai2.coMaXe(ma)) ||
            (coBai3 && bai3.coMaXe(ma));
    }

    void taoBai() {
        int ma;
        char size;

        cout << "Nhap ma bai: ";
        cin >> ma;
        cout << "Nhap kich thuoc (S/M/L): ";
        cin >> size;
        size = toupper((unsigned char)size);

        if (size != 'S' && size != 'M' && size != 'L') {
            cout << "Kich thuoc khong hop le!\n";
            return;
        }

        if (trungMaBai(ma)) {
            cout << "Ma bai da ton tai!\n";
            return;
        }

        BaiDoXe bai(ma, size);

        if (!coBai1) {
            bai1 = bai;
            coBai1 = true;
        }
        else if (!coBai2) {
            bai2 = bai;
            coBai2 = true;
        }
        else if (!coBai3) {
            bai3 = bai;
            coBai3 = true;
        }
        else {
            cout << "Da du 3 bai do xe!\n";
            return;
        }

        cout << "Tao bai thanh cong!\n";
    }

    void themXe() {
        int ma, gio, thoiLuong;
        string loai;

        cout << "Nhap ma xe: ";
        cin >> ma;

        if (trungMaXe(ma)) {
            cout << "Ma xe da ton tai!\n";
            return;
        }

        cout << "Nhap loai xe (Car/Motorcycle/Bicycle): ";
        cin >> loai;

        if (!Xe::laLoaiXeHopLe(loai)) {
            cout << "Loai xe khong hop le!\n";
            return;
        }

        cout << "Nhap gio vao (0-23): ";
        cin >> gio;
        cout << "Nhap thoi gian do (1-23): ";
        cin >> thoiLuong;

        if (gio < 0 || gio > 23 ||
            thoiLuong < 1 || thoiLuong > 23) {
            cout << "Thoi gian khong hop le!\n";
            return;
        }

        Xe xe(ma, loai, gio, thoiLuong);

        if (coBai1 && bai1.themXe(xe)) {
            cout << "Them vao bai " << bai1.layMaBai() << endl;
        }
        else if (coBai2 && bai2.themXe(xe)) {
            cout << "Them vao bai " << bai2.layMaBai() << endl;
        }
        else if (coBai3 && bai3.themXe(xe)) {
            cout << "Them vao bai " << bai3.layMaBai() << endl;
        }
        else {
            cout << "Khong con cho trong!\n";
        }
    }

    void xoaBai() {
        int ma;
        cout << "Nhap ma bai can xoa: ";
        cin >> ma;

        if (coBai1 && bai1.layMaBai() == ma) {
            coBai1 = false;
        }
        else if (coBai2 && bai2.layMaBai() == ma) {
            coBai2 = false;
        }
        else if (coBai3 && bai3.layMaBai() == ma) {
            coBai3 = false;
        }
        else {
            cout << "Khong tim thay bai!\n";
            return;
        }

        cout << "Xoa bai thanh cong!\n";
    }

    void layXe() {
        int ma;
        cout << "Nhap ma xe can lay: ";
        cin >> ma;

        if ((coBai1 && bai1.xoaXe(ma)) ||
            (coBai2 && bai2.xoaXe(ma)) ||
            (coBai3 && bai3.xoaXe(ma))) {
            cout << "Lay xe thanh cong!\n";
        }
        else {
            cout << "Khong tim thay xe!\n";
        }
    }

    void hienThiTatCa() {
        if (coBai1) bai1.hienThiThongTinBai();
        if (coBai2) bai2.hienThiThongTinBai();
        if (coBai3) bai3.hienThiThongTinBai();
    }

    void hienThiTheoBai() {
        int ma;
        cout << "Nhap ma bai: ";
        cin >> ma;

        if (coBai1 && bai1.layMaBai() == ma)
            bai1.hienThiXe();
        else if (coBai2 && bai2.layMaBai() == ma)
            bai2.hienThiXe();
        else if (coBai3 && bai3.layMaBai() == ma)
            bai3.hienThiXe();
        else
            cout << "Khong tim thay bai!\n";
    }

    void lietKeTheoLoai() {
        string loai;
        cout << "Nhap loai xe: ";
        cin >> loai;

        loai = Xe::chuanHoaLoaiXe(loai);

        if (loai == "") {
            cout << "Loai xe khong hop le!\n";
            return;
        }

        if (coBai1) bai1.lietKeTheoLoai(loai);
        if (coBai2) bai2.lietKeTheoLoai(loai);
        if (coBai3) bai3.lietKeTheoLoai(loai);
    }

    void thongKe() {
        string loai;
        double tong;
        int dem;

        for (int i = 1; i <= 3; i++) {
            if (i == 1) loai = "Car";
            if (i == 2) loai = "Motorcycle";
            if (i == 3) loai = "Bicycle";

            tong = 0;
            dem = 0;

            if (coBai1) {
                tong += bai1.tongPhi(loai);
                dem += bai1.demLoai(loai);
            }
            if (coBai2) {
                tong += bai2.tongPhi(loai);
                dem += bai2.demLoai(loai);
            }
            if (coBai3) {
                tong += bai3.tongPhi(loai);
                dem += bai3.demLoai(loai);
            }

            cout << "Loai xe: " << loai << endl;
            cout << "So luong: " << dem << endl;
            cout << "Phi trung binh: ";

            if (dem > 0)
                cout << tong / dem << endl;
            else
                cout << 0 << endl;
        }

        if (coBai1) {
            cout << "Bai " << bai1.layMaBai() << endl;
            cout << "Tong phi: "
                << bai1.tongPhi("Car")
                + bai1.tongPhi("Motorcycle")
                + bai1.tongPhi("Bicycle") << endl;
        }
        if (coBai2) {
            cout << "Bai " << bai2.layMaBai() << endl;
            cout << "Tong phi: "
                << bai2.tongPhi("Car")
                + bai2.tongPhi("Motorcycle")
                + bai2.tongPhi("Bicycle") << endl;
        }
        if (coBai3) {
            cout << "Bai " << bai3.layMaBai() << endl;
            cout << "Tong phi: "
                << bai3.tongPhi("Car")
                + bai3.tongPhi("Motorcycle")
                + bai3.tongPhi("Bicycle") << endl;
        }
    }

    void runMenu() {
        int chon;

        do {
            cout << "\n===== QUAN LY BAI DO XE =====\n";
            cout << "1. Tao bai do xe\n";
            cout << "2. Them xe vao bai\n";
            cout << "3. Xoa bai do xe\n";
            cout << "4. Lay xe ra khoi bai\n";
            cout << "5. Hien thi tat ca bai\n";
            cout << "6. Hien thi xe theo bai\n";
            cout << "7. Liet ke xe theo loai\n";
            cout << "8. Thong ke phi do xe\n";
            cout << "9. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> chon;

            switch (chon) {
            case 1: taoBai(); break;
            case 2: themXe(); break;
            case 3: xoaBai(); break;
            case 4: layXe(); break;
            case 5: hienThiTatCa(); break;
            case 6: hienThiTheoBai(); break;
            case 7: lietKeTheoLoai(); break;
            case 8: thongKe(); break;
            case 9: cout << "Ket thuc!\n"; break;
            default: cout << "Lua chon khong hop le!\n";
            }
        } while (chon != 9);
    }
};

int main() {
    HeThong ht;
    ht.runMenu();
    return 0;
}




Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
