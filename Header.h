//_CRT_SECURE_NO_WARNINGS
#ifndef BUS_TRANSPORT_H
#define BUS_TRANSPORT_H

#include <iostream>
#include <string>

using namespace std;

struct TuyenXeBuyt {
    int maTuyen;
    string tenTuyen;
    string diemDau;
    string diemCuoi;
    float cuLy;
    TuyenXeBuyt* nextTuyen;
};

struct CongTy {
    int maCty;
    string tenCty;
    string diaChi;
    TuyenXeBuyt* danhSachTuyen;
    CongTy* nextCty;
};

TuyenXeBuyt* ThemTuyenXeBuyt(int ma, const std::string& ten, const std::string& dau, const std::string& cuoi, float ly);
CongTy* ThemCongTy(int ma, const std::string& ten, const std::string& diaChi);
void ThemTuyenXeBuyt(CongTy* congTy, TuyenXeBuyt* tuyenMoi);
TuyenXeBuyt* NhapThongTinTuyenXeBuyt();
CongTy* NhapThongTinCongTy();
void XoaCongTy(CongTy*& danhSachCongTy, int maCtyCanXoa);
void XoaCongTy(CongTy*& danhSachCongTy, const std::string& tenCtyCanXoa);
void TimTuyenXeBuyt(CongTy* danhSachCongTy, int maTuyenCanTim);
void TimTuyenXeBuyt(CongTy* danhSachCongTy, const std::string& tenTuyenCanTim);
void ThemTuyenChoCongTy(CongTy* danhSachCongTy, int maCongTyThemTuyen);

#endif 
