/*
 * Cmd.hpp
 * Copyright (C) 2010 Christian Stimming
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, contact:
 *
 * Free Software Foundation           Voice:  +1-617-542-5942
 * 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652
 * Boston, MA  02110-1301,  USA       gnu@gnu.org
 */

#include "Cmd.hpp"
#include "gnc/Split.hpp"
#include "gnc/Account.hpp"
#include "gnc/Transaction.hpp"
#include <QObject>

namespace gnc
{

// Explicit instantiations to check for compiler errors
template class Cmd<Account, QString>;

namespace cmd
{

// ////////////////////////////////////////////////////////////

QUndoCommand* setSplitMemo(Split& t, const QString& newValue)
{
    return new Cmd<Split, QString>(QObject::tr("Edit Split Memo"),
                                   t, &Split::setMemo,
                                   &Split::getMemo, newValue);
}

QUndoCommand* setSplitAction(Split& t, const QString& newValue)
{
    return new Cmd<Split, QString>(QObject::tr("Edit Split Action"),
                                   t, &Split::setAction,
                                   &Split::getAction, newValue);
}

QUndoCommand* setSplitReconcile(Split& t, char newValue)
{
    // Special third argument: The setter function takes a value
    // directly, instead of a const-reference, so the template type
    // must be given explicitly.
    return new Cmd<Split, char, void (Split::*)(char)>(QObject::tr("Edit Split Reconcile"),
            t, &Split::setReconcile,
            &Split::getReconcile, newValue);
}

QUndoCommand* setSplitAmount(Split& t, const Numeric& newValue)
{
    return new Cmd<Split, Numeric>(QObject::tr("Edit Split Amount"),
                                   t, &Split::setAmount,
                                   &Split::getAmount, newValue);
}

QUndoCommand* setSplitValue(Split& t, const Numeric& newValue)
{
    return new Cmd<Split, Numeric>(QObject::tr("Edit Split Value"),
                                   t, &Split::setValue,
                                   &Split::getValue, newValue);
}

// ////////////////////////////////////////////////////////////

QUndoCommand* setTransactionNum(Transaction& t, const QString& newValue)
{
    return new Cmd<Transaction, QString>(QObject::tr("Edit Transaction Number"),
                                         t, &Transaction::setNum,
                                         &Transaction::getNum, newValue);
}

QUndoCommand* setTransactionDescription(Transaction& t, const QString& newValue)
{
    return new Cmd<Transaction, QString>(QObject::tr("Edit Transaction Description"),
                                         t, &Transaction::setDescription,
                                         &Transaction::getDescription, newValue);
}

QUndoCommand* setTransactionNotes(Transaction& t, const QString& newValue)
{
    return new Cmd<Transaction, QString>(QObject::tr("Edit Transaction Notes"),
                                         t, &Transaction::setNotes,
                                         &Transaction::getNotes, newValue);
}

QUndoCommand* setTransactionDate(Transaction& t, const QDateTime& newValue)
{
    return new Cmd<Transaction, QDateTime>(QObject::tr("Edit Transaction Date"),
                                           t, &Transaction::setDatePosted,
                                           &Transaction::getDatePosted, newValue);
}


} // END namespace cmd


} // END namespace gnc