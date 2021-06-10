#include "RecordTable.h"

RecordTable::RecordTable() : mTable() {

}

RecordTable::~RecordTable() {

}

void RecordTable::ReadTable() {
    std::ifstream record_file;
    record_file.open("assets/data/record", std::ios::in);
    mTable.fill(Record{"-", 0});
    if (!record_file) {
        RECORD = 0;
    }
    else {
        for (int i = 0; i < mTable.size() && !record_file.eof(); i++) {
            Record record;
            record_file >> record.nickname >> record.score;
            if (!record.score) record.nickname = "-";
            mTable[i] = record;
        }
        RECORD = mTable.front().score;
        record_file.close();
    }
}

void RecordTable::UpdateTable(std::string name) {
    if (IsRecord()) {
        int i;
        for (i = 0; i < mTable.size(); i++) {
            if (SCORE > mTable[i].score) {
                for (int j = mTable.size() - 1; j > i; j--) {
                    mTable[j].nickname = mTable[j - 1].nickname;
                    mTable[j].score = mTable[j - 1].score;
                }
                mTable[i].score = SCORE;
                mTable[i].nickname = name;
                break;
            }
        }
        RECORD = mTable.front().score;


        std::ofstream record_file;
        record_file.open("assets/data/record", std::ios::out);
        if (record_file) {
            for (auto record : mTable) {
                record_file << record.nickname << " " << record.score << "\n";
            }
            record_file.close();
        }
    }
}

bool RecordTable::IsRecord() {
    return SCORE > mTable.back().score;
}