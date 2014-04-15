/*

This file is part of Rooster from Gallus

Copyright (C) 2014 Adam Oren and Gallus <gallussoft@gmail.com>

Redistribution and use of this program's code, including all
included support files, such as headers, or any derivative works are
permitted provided that the following conditions are met:

* Redistributions may not be sold, nor may they be used in a
  commercial product.

* Redistributions that are modified from the original source must
  include the complete source code, including the source code for all
  components used by a binary built from the modified sources.
  However, as a special exception, the source code distributed need
  not include anything that is normally distributed (in either source
  or binary form) with the major components (compiler, kernel, and so
  on) of the operating system on which the executable runs, unless
  that component itself accompanies the executable.

* Neither the name of the copright holder, the copyright holder's
  organizatiom, nor the names of its contributors may be used to
  endorse or promote products derived from this software without
  specific prior written permission.

* Redistributions must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the
  distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#include "rooster.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rooster w;
    w.show();

    return a.exec();
}