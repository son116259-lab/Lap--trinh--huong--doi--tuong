#include<iostream>
class phuong_tien {
private:
    int ma_xe;
    string loai_xe;
    int gio_vao;
    int tg_do;

public:
    phuong_tien();
    phuong_tien(int ma, string loai, int gio, int tg);
    int lay_ma_xe() const;
    string lay_loai_xe() const;
    double tinh_phi() const;
    void hien_thi() const;
};
phuong_tien ;; phuong_tien(){
	ma_xe = 0;
	loai_xe = "";
	gio_vao = 0;
	tg_do = 0;
	phi_do_xe = 0.0;
}
phuong_tien ;; phuong_tien(int ma, string loai, int gio, int tg, double phi){
	ma_xe = ma;
	loai_xe = loai;
	gio_vao = gio;
	tg_do = tg;
	phi_do_xe = phi
}
void tinh_phi(){
	double = tien 0.0;
	string loaixe = loai_xe
	transform(loaixe.begin(), loaixe.end(), loaixe.begin(), ;;tolower);
	if (loaixe == "car"){
		tien = 6.0;
	}
	if ( loaixe == "motorbike"){
		tien = 3.0;
	}
	if (loaixe == "bicycle"){
		tien = 2.0;
	}
	tongphi = 0.0;
	bool lagiocaodiem = (())
	for (int i = 0; i < tg_do; i++){
		int tg_hientai = (gio_vao + i = 1) %24;
		bool lagiocaodiem = ((tg_hientai >= 6) && (tg_hientai <= 9) || (tg_hientai >= 15) && (tg_hientai <= 10));
		if ( i < 2){
			if(lagiocaodiem){
				tongphi *= 1.30;
			}
			else{
				tongphi *= 0.95;
			}
		}
	}
	tongphi = phi_do_xe;
}


class bai_xe {
private:
    int ma_bai;
    char kich_thuoc;
    phuong_tien pt1, pt2, pt3;  
    bool co1, co2, co3;

public:
    bai_xe();
    bai_xe(int ma, char kt);

    int lay_ma() const;
    bool them(phuong_tien v);
    bool xoa(int ma_xe);
    bool chua(int ma_xe) const;
    void hien_thi() const;
    bool co_loai(string loai, int& dem, double& tong) const;
};
bool bai_xe::them(phuong_tien v) {
    int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
    if (cap >= 1 && !co1) { pt1 = v; co1 = true; return true; }
    if (cap >= 2 && !co2) { pt2 = v; co2 = true; return true; }
    if (cap >= 3 && !co3) { pt3 = v; co3 = true; return true; }
    return false;
}

bool bai_xe::xoa(int ma_xe) {
    if (co1 && pt1.lay_ma_xe() == ma_xe) {
        if (co2) {
            pt1 = pt2;
            if (co3) { pt2 = pt3; co3 = false; }
            else co2 = false;
        } else co1 = false;
        return true;
    }
    if (co2 && pt2.lay_ma_xe() == ma_xe) {
        if (co3) { pt2 = pt3; co3 = false; }
        else co2 = false;
        return true;
    }
    if (co3 && pt3.lay_ma_xe() == ma_xe) {
        co3 = false;
        return true;
    }
    return false;
}

bool bai_xe::chua(int ma_xe) const {
    if (co1 && pt1.lay_ma_xe() == ma_xe) return true;
    if (co2 && pt2.lay_ma_xe() == ma_xe) return true;
    if (co3 && pt3.lay_ma_xe() == ma_xe) return true;
    return false;
}

void bai_xe::hien_thi() const {
    int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
    int so_xe = co1 + co2 + co3;
    cout << "Bai " << ma_bai << " [" << kich_thuoc << "] "
         << so_xe << "/" << cap << " xe\n";
    if (co1) pt1.hien_thi();
    if (co2) pt2.hien_thi();
    if (co3) pt3.hien_thi();
}

bool bai_xe::co_loai(string loai, int& dem, double& tong) const {
    dem = 0; tong = 0;
    if (co1 && pt1.lay_loai_xe() == loai) { ++dem; tong += pt1.tinh_phi(); }
    if (co2 && pt2.lay_loai_xe() == loai) { ++dem; tong += pt2.tinh_phi(); }
    if (co3 && pt3.lay_loai_xe() == loai) { ++dem; tong += pt3.tinh_phi(); }
    return dem > 0;
}
class SystemInterface {
private:
    bai_xe bai1, bai2, bai3;   
    bool co1, co2, co3; 

public:
    SystemInterface();
    void runMenu();/
};
void SystemInterface::runMenu() {
    int chon;
    while (true) {
        cout << "\n===== QUAN LY BAI DO XE =====\n";
        cout << "1. Tao bai do\n";
        cout << "2. Them xe\n";
        cout << "3. Xoa bai do\n";
        cout << "4. Lay xe ra\n";
        cout << "5. Hien thi tat ca bai do\n";
        cout << "6. Hien thi xe theo bai\n";
        cout << "7. Liet ke xe theo loai\n";
        cout << "8. Bao cao phi trung binh\n";
        cout << "9. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        if (chon == 1) {
