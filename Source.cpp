#include "Header.h"

TuyenXeBuyt* ThemTuyenXeBuyt(int ma, const std::string& ten, const std::string& dau, const std::string& cuoi, float ly) {
    TuyenXeBuyt* tuyenMoi = new TuyenXeBuyt;
    tuyenMoi->maTuyen = ma;
    tuyenMoi->tenTuyen = ten;
    tuyenMoi->diemDau = dau;
    tuyenMoi->diemCuoi = cuoi;
    tuyenMoi->cuLy = ly;
    tuyenMoi->nextTuyen = nullptr;
    return tuyenMoi;
}

CongTy* ThemCongTy(int ma, const std::string& ten, const std::string& diaChi) {
    CongTy* ctyMoi = new CongTy;
    ctyMoi->maCty = ma;
    ctyMoi->tenCty = ten;
    ctyMoi->diaChi = diaChi;
    ctyMoi->danhSachTuyen = nullptr;
    ctyMoi->nextCty = nullptr;
    return ctyMoi;
}

void ThemTuyenXeBuyt(CongTy* congTy, TuyenXeBuyt* tuyenMoi) {
    if (congTy->danhSachTuyen == nullptr) {
        congTy->danhSachTuyen = tuyenMoi;
    }
    else {
        tuyenMoi->nextTuyen = congTy->danhSachTuyen;
        congTy->danhSachTuyen = tuyenMoi;
    }
}

TuyenXeBuyt* NhapThongTinTuyenXeBuyt() {
    int ma;
    string ten, dau, cuoi;
    float ly;

    cout << "Nhap ma tuyen: ";
    cin >> ma;
    cout << "Nhap ten tuyen: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap diem dau: ";
    getline(cin, dau);
    cout << "Nhap diem cuoi: ";
    getline(cin, cuoi);
    cout << "Nhap cu ly: ";
    cin >> ly;

    return ThemTuyenXeBuyt(ma, ten, dau, cuoi, ly);
}

CongTy* NhapThongTinCongTy() {
    int ma;
    string ten, diaChi;

    cout << "Nhap ma cong ty: ";
    cin >> ma;
    cout << "Nhap ten cong ty: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap dia chi cong ty: ";
    getline(cin, diaChi);

    return ThemCongTy(ma, ten, diaChi);
}
//xóa công ty ( mã công ty)
void XoaCongTy(CongTy*& danhSachCongTy, int maCtyCanXoa) {
    CongTy* temp = danhSachCongTy;
    CongTy* prev = nullptr;

    while (temp != nullptr && temp->maCty != maCtyCanXoa) {
        prev = temp;
        temp = temp->nextCty;
    }

    if (temp != nullptr) {
        if (prev != nullptr) {
            prev->nextCty = temp->nextCty;
        }
        else {
            danhSachCongTy = temp->nextCty;
        }
        delete temp;
        cout << "Da xoa cong ty co ma " << maCtyCanXoa << endl;
    }
    else {
        cout << "Khong tim thay cong ty co ma " << maCtyCanXoa << " de xoa ><" << endl;
    }
}
//xóa công ty (tên công ty)
void XoaCongTy(CongTy*& danhSachCongTy, const std::string& tenCtyCanXoa) {
    CongTy* temp = danhSachCongTy;
    CongTy* prev = nullptr;

    while (temp != nullptr && temp->tenCty != tenCtyCanXoa) {
        prev = temp;
        temp = temp->nextCty;
    }

    if (temp != nullptr) {
        if (prev != nullptr) {
            prev->nextCty = temp->nextCty;
        }
        else {
            danhSachCongTy = temp->nextCty;
        }
        delete temp;
        cout << "Da xoa cong ty co ten " << tenCtyCanXoa << endl;
    }
    else {
        cout << "Khong tim thay cong ty co ten " << tenCtyCanXoa << " de xoa." << endl;
    }
}

void TimTuyenXeBuyt(CongTy* danhSachCongTy, int maTuyenCanTim) {
    CongTy* tempCongTy
        = danhSachCongTy;
    while (tempCongTy != nullptr) {
        TuyenXeBuyt* tempTuyen = tempCongTy->danhSachTuyen;
        while (tempTuyen != nullptr) {
            if (tempTuyen->maTuyen == maTuyenCanTim) {
                cout << "Tim thay tuyen xe buyt co ma " << maTuyenCanTim << " cua cong ty " << tempCongTy->tenCty << :endl;
                return;
            }
            tempTuyen = tempTuyen->nextTuyen;
        }
        tempCongTy = tempCongTy->nextCty;
    }

   cout << "Khong tim thay tuyen xe buyt co ma " << maTuyenCanTim << " trong he thong." << endl;
}
//tìm tuyến xe bus
void TimTuyenXeBuyt(CongTy* danhSachCongTy, const string& tenTuyenCanTim) {
    CongTy* tempCongTy = danhSachCongTy;
    while (tempCongTy != nullptr) {
        TuyenXeBuyt* tempTuyen = tempCongTy->danhSachTuyen;
        while (tempTuyen != nullptr) {
            if (tempTuyen->tenTuyen == tenTuyenCanTim) {
                std::cout << "Tim thay tuyen xe buyt co ten " << tenTuyenCanTim << " cua cong ty " << tempCongTy->tenCty << endl;
                return;
            }
            tempTuyen = tempTuyen->nextTuyen;
        }
        tempCongTy = tempCongTy->nextCty;
    }

    std::cout << "Khong tim thay tuyen xe buyt co ten " << tenTuyenCanTim << " trong he thong." << std::endl;
}
//thêm tuyến xe bus
void ThemTuyenChoCongTy(CongTy* danhSachCongTy, int maCongTyThemTuyen) {
    CongTy* tempCongTy = danhSachCongTy;
    while (tempCongTy != nullptr) {
        if (tempCongTy->maCty == maCongTyThemTuyen) {
            TuyenXeBuyt* tuyenMoi = NhapThongTinTuyenXeBuyt();
            ThemTuyenXeBuyt(tempCongTy, tuyenMoi);
            std::cout << "Da them tuyen xe buyt cho cong ty co ma " << maCongTyThemTuyen << std::endl;
            return;
        }
        tempCongTy = tempCongTy->nextCty;
    }

    std::cout << "Khong tim thay cong ty co ma " << maCongTyThemTuyen << " trong he thong." << std::endl;
}
