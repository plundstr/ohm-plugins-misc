/*************************************************************************
Copyright (C) 2010 Nokia Corporation.

These OHM Modules are free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation
version 2.1 of the License.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
USA.
*************************************************************************/


#include "backlight-plugin.h"

/********************
 * null_init
 ********************/
void
null_init(backlight_context_t *ctx, OhmPlugin *plugin)
{
    (void)ctx;
    (void)plugin;
}


/********************
 * null_exit
 ********************/
void
null_exit(backlight_context_t *ctx)
{
    (void)ctx;
}


/********************
 * null_enforce
 ********************/
int
null_enforce(backlight_context_t *ctx)
{
    OHM_INFO("backlight-null: backlight state is now '%s'", ctx->action);
    
    return TRUE;
}


/*
 * Local Variables:
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 *
 */
