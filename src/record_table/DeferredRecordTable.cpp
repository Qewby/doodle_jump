#include "DeferredRecordTable.h"

void DeferredRecordTable::ReadTable()
{
    return GetRecordTable().ReadTable();
}

void DeferredRecordTable::UpdateTable(std::string name)
{
    return GetRecordTable().UpdateTable(name);
}

bool DeferredRecordTable::IsRecord()
{
    return GetRecordTable().IsRecord();
}

void DeferredRecordTable::Draw()
{
    return GetRecordTable().Draw();
}

bool DeferredRecordTable::HandleClick()
{
    return GetRecordTable().HandleClick();
}

RecordTable& DeferredRecordTable::GetRecordTable()
{
    if (!mpRecordTable)
    {
        mpRecordTable = std::make_unique<RecordTable>(mrRenderer);
    }
    return *mpRecordTable;
}
