#ifndef DOODLE_JUMP_RECORDTABLE_H
#define DOODLE_JUMP_RECORDTABLE_H

#include <fstream>
#include <array>

extern unsigned long long  SCORE;
extern unsigned long long  RECORD;

class RecordTable {
public:
    RecordTable();
    ~RecordTable();

    void ReadTable();
    void UpdateTable(std::string name);
    bool IsRecord();
private:
    struct Record {
        std::string nickname;
        unsigned long long score;
    };
    std::array<Record, 5> mTable;
};


#endif //DOODLE_JUMP_RECORDTABLE_H
