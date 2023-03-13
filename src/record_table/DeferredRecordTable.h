#ifndef DOODLE_JUMP_DEFEREDRECORDTABLE_H
#define DOODLE_JUMP_DEFEREDRECORDTABLE_H

#include <memory>

#include "IRecordTable.h"
#include "RecordTable.h"

extern unsigned long long  SCORE;
extern unsigned long long  RECORD;

extern std::pair<bool, std::pair<int, int>> gLeftMouseClickPosition;
extern std::pair<int, int> gMousePosition;

class DeferredRecordTable : public IRecordTable {
public:
    DeferredRecordTable(Renderer& renderer) : IRecordTable(renderer), mpRecordTable(nullptr) {}
    virtual ~DeferredRecordTable() {};

    void ReadTable() override;
    void UpdateTable(std::string name) override;
    bool IsRecord() override;

    void Draw() override;
    bool HandleClick() override;
    
private:
    std::unique_ptr<RecordTable> mpRecordTable;

    RecordTable& GetRecordTable();
};

#endif //DOODLE_JUMP_DEFEREDRECORDTABLE_H
