/****************************************************************************
** libebml : parse EBML files, see http://embl.sourceforge.net/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
**
** This file is part of libebml.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** See http://www.gnu.org/licenses/lgpl-2.1.html for LGPL licensing information.
**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
  \file
  \version \$Id: EbmlContexts.cpp 639 2004-07-09 20:59:14Z mosu $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "ebml/EbmlContexts.h"
#include "ebml/EbmlCrc32.h"
#include "ebml/EbmlVoid.h"

namespace libebml {

static constexpr EbmlSemantic EbmlGlobal_ContextList[2] =
{
  EbmlSemantic(false, false, EBML_INFO(EbmlCrc32)),   ///< EbmlCrc32
  EbmlSemantic(false, false, EBML_INFO(EbmlVoid)),    ///< EbmlVoid
};

const EbmlSemanticContext Context_EbmlGlobal = EbmlSemanticContext(0, nullptr, nullptr, GetEbmlGlobal_Context, nullptr);

static const EbmlSemanticContext EbmlGlobal_Context = EbmlSemanticContext(countof(EbmlGlobal_ContextList), EbmlGlobal_ContextList, nullptr, GetEbmlGlobal_Context, nullptr);

const EbmlSemanticContext & GetEbmlGlobal_Context()
{
  return EbmlGlobal_Context;
}

} // namespace libebml
