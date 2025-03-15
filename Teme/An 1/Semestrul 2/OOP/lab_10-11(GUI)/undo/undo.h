//
// Created by Știube Denis on 20.04.2024.
//

#ifndef LAB_6_PB_7_UNDO_H
#define LAB_6_PB_7_UNDO_H
#include <string>
#include "../repository/repository.h"
using std::string;

class ActiuneUndo{
public:
    virtual void doUndo() = 0;
    virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo{
    repoAbstract& repo;
    Medicament medAdaugat;
public:
    UndoAdauga(repoAbstract& repo, const Medicament& medAdaugat): repo{repo}, medAdaugat{medAdaugat}{

    }
    UndoAdauga() = delete;

    void doUndo() override;

};

class UndoSterge : public ActiuneUndo{
    repoAbstract& repo;
    Medicament medSters;
public:
    UndoSterge(repoAbstract& repo, const Medicament& medSters): repo{repo}, medSters{medSters}{

    }

    void doUndo() override;
};

class UndoModifica : public ActiuneUndo{
    repoAbstract& repo;
    Medicament medVechi;
    Medicament medNou;
public:
    UndoModifica(repoAbstract& repo, Medicament& medVechi, Medicament& medNou): repo{repo}, medVechi{medVechi}, medNou{medNou}{

    }

    void doUndo() override;
};


#endif //LAB_6_PB_7_UNDO_H
