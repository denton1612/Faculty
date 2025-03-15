//
// Created by Știube Denis on 20.04.2024.
//

#include "undo.h"

void UndoAdauga::doUndo() {
    repo.deleteMedicament(medAdaugat);
}

void UndoSterge::doUndo() {
    repo.addMedicament(medSters);
}

void UndoModifica::doUndo() {
    repo.updateMedicament(medNou, medVechi);
}