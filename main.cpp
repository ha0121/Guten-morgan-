#include "Header.h"
#include "Source.cpp"

int main() {
    CongTy* danhSachCongTy = nullptr;

    int soCongTy;
    std::cout << "Nhap so cong ty: ";
    std::cin >> soCongTy;

    for (int i = 0; i < soCongTy; ++i) {
        CongTy* congTyMoi = NhapThongTinCongTy();
        int soTuyenXeBuyt;
        std::cout << "Nhap so tuyen xe buyt cua cong ty " << congTyMoi->tenCty << ": ";
        std::cin >> soTuyenXeBuyt;

        for (int j = 0; j < soTuyenXeBuyt; ++j) {
            TuyenXeBuyt* tuyenMoi = NhapThongTinTuyenXeBuyt();
            ThemTuyenXeBuyt(congTyMoi, tuyenMoi);
        }

        if (danhSachCongTy == nullptr) {
            danhSachCongTy = congTyMoi;
        }
        else {
            congTyMoi->nextCty = danhSachCongTy;
            danhSachCongTy = congTyMoi;
        }
    }

    // Th�m c�ng ty t?i v? tr� b?t k?
    CongTy* congTyMoi = NhapThongTinCongTy();
    int viTri;
    std::cout << "Nhap vi tri muon them cong ty: ";
    std::cin >> viTri;

    if (viTri == 0) {
        congTyMoi->nextCty = danhSachCongTy;
        danhSachCongTy = congTyMoi;
    }
    else {
        CongTy* temp = danhSachCongTy;
        for (int i = 0; i < viTri - 1 && temp != nullptr; ++i) {
            temp = temp->nextCty;
        }

        if (temp != nullptr) {
            congTyMoi->nextCty = temp->nextCty;
            temp->nextCty = congTyMoi;
        }
        else {
            std::cout << "Vi tri khong hop le. Khong the them cong ty." << std::endl;
        }
    }

    // X�a c�ng ty khi bi?t M� Cty ho?c t�n C�ng ty
    int luaChon;
    std::cout << "Chon cach xoa cong ty (1: Ma Cty, 2: Ten Cong Ty): ";
    std::cin >> luaChon;

    if (luaChon == 1) {
        int maCtyCanXoa;
        std::cout << "Nhap Ma Cong Ty can xoa: ";
        std::cin >> maCtyCanXoa;
        XoaCongTy(danhSachCongTy, maCtyCanXoa);
    }
    else if (luaChon == 2) {
        std::string tenCtyCanXoa;
        std::cout << "Nhap Ten Cong Ty can xoa: ";
        std::cin.ignore();
        std::getline(std::cin, tenCtyCanXoa);
        XoaCongTy(danhSachCongTy, tenCtyCanXoa);
    }
    else {
        std::cout << "Lua chon khong hop le." << std::endl;
    }

    // T�m tuy?n xe bu�t khi bi?t t�n tuy?n ho?c M� tuy?n
    int luaChonTim;
    std::cout << "Chon cach tim tuyen xe buyt (1: Ma Tuyen, 2: Ten Tuyen): ";
    std::cin >> luaChonTim;

    if (luaChonTim == 1) {
        int maTuyenCanTim;
        std::cout << "Nhap Ma Tuyen can tim: ";
        std::cin >> maTuyenCanTim;
        TimTuyenXeBuyt(danhSachCongTy, maTuyenCanTim);
    }
    else if (luaChonTim == 2) {
        std::string tenTuyenCanTim;
        std::cout << "Nhap Ten Tuyen can tim: ";
        std::cin.ignore
                    ();
        std::getline(std::cin, tenTuyenCanTim);
        TimTuyenXeBuyt(danhSachCongTy, tenTuyenCanTim);
    } else {
        std::cout << "Lua chon khong hop le." << std::endl;
    }

    // Th�m m?t tuy?n xe bu�t v�o m?t c�ng ty khi bi?t m� C�ng ty
    int maCongTyThemTuyen;
    std::cout << "Nhap Ma Cong Ty muon them tuyen xe buyt: ";
    std::cin >> maCongTyThemTuyen;
    ThemTuyenChoCongTy(danhSachCongTy, maCongTyThemTuyen);

    // Gi?i ph�ng b? nh?
    CongTy* tempCongTy = danhSachCongTy;
    while (tempCongTy != nullptr) {
        CongTy* nextCongTy = tempCongTy->nextCty;
        TuyenXeBuyt* tempTuyen = tempCongTy->danhSachTuyen;
        while (tempTuyen != nullptr) {
            TuyenXeBuyt* nextTuyen = tempTuyen->nextTuyen;
            delete tempTuyen;
            tempTuyen = nextTuyen;
        }
        delete tempCongTy;
        tempCongTy = nextCongTy;
    }

    return 0;
}

