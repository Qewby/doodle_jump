#ifndef DOODLE_JUMP_IRECORDTABLE_H
#define DOODLE_JUMP_IRECORDTABLE_H

#include "../Drawable.h"

class IRecordTable : public Drawable {
public:
    IRecordTable(Renderer& renderer) : Drawable(renderer) {}
    virtual ~IRecordTable() = default;

    virtual void ReadTable() = 0;
    virtual void UpdateTable(std::string name) = 0;
    virtual bool IsRecord() = 0;

    virtual bool HandleClick() = 0;
};


#endif //DOODLE_JUMP_IRECORDTABLE_H
