/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2014-2015 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU Lesser General Public License Version 2.1
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#if !defined (__APPSTREAM_GLIB_H) && !defined (AS_COMPILATION)
#error "Only <appstream-glib.h> can be included directly."
#endif

#ifndef __AS_APP_H
#define __AS_APP_H

#include <glib-object.h>

#include "as-bundle.h"
#include "as-enums.h"
#include "as-icon.h"
#include "as-provide.h"
#include "as-release.h"
#include "as-screenshot.h"
#include "as-content-rating.h"
#include "as-translation.h"

G_BEGIN_DECLS

#define AS_TYPE_APP (as_app_get_type ())
G_DECLARE_DERIVABLE_TYPE (AsApp, as_app, AS, APP, GObject)

struct _AsAppClass
{
	GObjectClass		parent_class;
	/*< private >*/
	void (*_as_reserved1)	(void);
	void (*_as_reserved2)	(void);
	void (*_as_reserved3)	(void);
	void (*_as_reserved4)	(void);
	void (*_as_reserved5)	(void);
	void (*_as_reserved6)	(void);
	void (*_as_reserved7)	(void);
	void (*_as_reserved8)	(void);
};

/**
 * AsAppParseFlags:
 * @AS_APP_PARSE_FLAG_NONE:		No special actions to use
 * @AS_APP_PARSE_FLAG_USE_HEURISTICS:	Use heuristic to infer properties
 * @AS_APP_PARSE_FLAG_KEEP_COMMENTS:	Save comments from the file
 * @AS_APP_PARSE_FLAG_CONVERT_TRANSLATABLE:	Allow translatable flags like <_p>
 * @AS_APP_PARSE_FLAG_APPEND_DATA:	Append new data rather than replacing
 * @AS_APP_PARSE_FLAG_ALLOW_VETO:	Do not return errors for vetoed apps
 * @AS_APP_PARSE_FLAG_USE_FALLBACKS:	Fall back to suboptimal data where required
 *
 * The flags to use when parsing resources.
 **/
typedef enum {
	AS_APP_PARSE_FLAG_NONE,
	AS_APP_PARSE_FLAG_USE_HEURISTICS	= 1,	/* Since: 0.1.2 */
	AS_APP_PARSE_FLAG_KEEP_COMMENTS		= 2,	/* Since: 0.1.6 */
	AS_APP_PARSE_FLAG_CONVERT_TRANSLATABLE	= 4,	/* Since: 0.1.6 */
	AS_APP_PARSE_FLAG_APPEND_DATA		= 8,	/* Since: 0.1.8 */
	AS_APP_PARSE_FLAG_ALLOW_VETO		= 16,	/* Since: 0.2.5 */
	AS_APP_PARSE_FLAG_USE_FALLBACKS		= 32,	/* Since: 0.4.1 */
	/*< private >*/
	AS_APP_PARSE_FLAG_LAST,
} AsAppParseFlags;

/**
 * AsAppSubsumeFlags:
 * @AS_APP_SUBSUME_FLAG_NONE:		No special actions to use
 * @AS_APP_SUBSUME_FLAG_NO_OVERWRITE:	Do not overwrite already set properties
 * @AS_APP_SUBSUME_FLAG_BOTH_WAYS:	Copy unset properties both ways
 * @AS_APP_SUBSUME_FLAG_PARTIAL:	Only subsume a safe subset
 *
 * The flags to use when subsuming applications.
 **/
typedef enum {
	AS_APP_SUBSUME_FLAG_NONE,
	AS_APP_SUBSUME_FLAG_NO_OVERWRITE = 1,	/* Since: 0.1.4 */
	AS_APP_SUBSUME_FLAG_BOTH_WAYS	 = 2,	/* Since: 0.1.4 */
	AS_APP_SUBSUME_FLAG_PARTIAL	 = 4,	/* Since: 0.2.2 */
	/*< private >*/
	AS_APP_SUBSUME_FLAG_LAST,
} AsAppSubsumeFlags;

/**
 * AsAppError:
 * @AS_APP_ERROR_FAILED:			Generic failure
 * @AS_APP_ERROR_INVALID_TYPE:			Invalid type
 *
 * The error type.
 **/
typedef enum {
	AS_APP_ERROR_FAILED,
	AS_APP_ERROR_INVALID_TYPE,
	/*< private >*/
	AS_APP_ERROR_LAST
} AsAppError;

/**
 * AsAppValidateFlags:
 * @AS_APP_VALIDATE_FLAG_NONE:			No extra flags to use
 * @AS_APP_VALIDATE_FLAG_RELAX:			Relax the checks
 * @AS_APP_VALIDATE_FLAG_STRICT:		Make the checks more strict
 * @AS_APP_VALIDATE_FLAG_NO_NETWORK:		Do not use the network
 * @AS_APP_VALIDATE_FLAG_ALL_APPS:		Check all applications in a store
 *
 * The flags to use when validating.
 **/
typedef enum {
	AS_APP_VALIDATE_FLAG_NONE		= 0,	/* Since: 0.1.4 */
	AS_APP_VALIDATE_FLAG_RELAX		= 1,	/* Since: 0.1.4 */
	AS_APP_VALIDATE_FLAG_STRICT		= 2,	/* Since: 0.1.4 */
	AS_APP_VALIDATE_FLAG_NO_NETWORK		= 4,	/* Since: 0.1.4 */
	AS_APP_VALIDATE_FLAG_ALL_APPS		= 8,	/* Since: 0.2.6 */
	/*< private >*/
	AS_APP_VALIDATE_FLAG_LAST
} AsAppValidateFlags;

/**
 * AsAppTrustFlags:
 * @AS_APP_TRUST_FLAG_COMPLETE:			Trusted data with no validation
 * @AS_APP_TRUST_FLAG_CHECK_DUPLICATES:		Check for duplicates
 * @AS_APP_TRUST_FLAG_CHECK_VALID_UTF8:		Check for valid UTF-8
 *
 * The flags to use when checking input.
 **/
typedef enum {
	AS_APP_TRUST_FLAG_COMPLETE		= 0,	/* Since: 0.2.2 */
	AS_APP_TRUST_FLAG_CHECK_DUPLICATES	= 1,	/* Since: 0.2.2 */
	AS_APP_TRUST_FLAG_CHECK_VALID_UTF8	= 2,	/* Since: 0.2.2 */
	/*< private >*/
	AS_APP_TRUST_FLAG_LAST
} AsAppTrustFlags;

/**
 * AsAppSourceKind:
 * @AS_APP_SOURCE_KIND_UNKNOWN:			Not sourced from a file
 * @AS_APP_SOURCE_KIND_APPSTREAM:		Sourced from a AppStream file
 * @AS_APP_SOURCE_KIND_DESKTOP:			Sourced from a desktop file
 * @AS_APP_SOURCE_KIND_APPDATA:			Sourced from a AppData file
 * @AS_APP_SOURCE_KIND_METAINFO:		Sourced from a MetaInfo file
 * @AS_APP_SOURCE_KIND_INF:			Sourced from a inf file
 *
 * The source kind.
 **/
typedef enum {
	AS_APP_SOURCE_KIND_UNKNOWN,			/* Since: 0.1.4 */
	AS_APP_SOURCE_KIND_APPSTREAM,			/* Since: 0.1.4 */
	AS_APP_SOURCE_KIND_DESKTOP,			/* Since: 0.1.4 */
	AS_APP_SOURCE_KIND_APPDATA,			/* Since: 0.1.4 */
	AS_APP_SOURCE_KIND_METAINFO,			/* Since: 0.1.7 */
	AS_APP_SOURCE_KIND_INF,				/* Since: 0.3.5 */
	/*< private >*/
	AS_APP_SOURCE_KIND_LAST
} AsAppSourceKind;

/**
 * AsAppKind:
 * @AS_APP_KIND_UNKNOWN:		Type invalid or not known
 * @AS_APP_KIND_DESKTOP:		A desktop application
 * @AS_APP_KIND_FONT:			A font add-on
 * @AS_APP_KIND_CODEC:			A codec add-on
 * @AS_APP_KIND_INPUT_METHOD:		A input method add-on
 * @AS_APP_KIND_WEB_APP:		A web appication
 * @AS_APP_KIND_SOURCE:			A software source
 * @AS_APP_KIND_ADDON:			An addon, e.g. a plugin
 * @AS_APP_KIND_FIRMWARE:		A firmware update
 * @AS_APP_KIND_RUNTIME:		Runtime platform
 * @AS_APP_KIND_GENERIC:		Generic component
 * @AS_APP_KIND_OS_UPDATE:		Operating system update
 * @AS_APP_KIND_OS_UPGRADE:		Operating system upgrade
 * @AS_APP_KIND_SHELL_EXTENSION:	GNOME Shell extension
 * @AS_APP_KIND_LOCALIZATION:		Localization data
 *
 * The component type.
 **/
typedef enum {
	AS_APP_KIND_UNKNOWN,		/* Since: 0.5.10 */
	AS_APP_KIND_DESKTOP,		/* Since: 0.5.10 */
	AS_APP_KIND_FONT,		/* Since: 0.5.10 */
	AS_APP_KIND_CODEC,		/* Since: 0.5.10 */
	AS_APP_KIND_INPUT_METHOD,	/* Since: 0.5.10 */
	AS_APP_KIND_WEB_APP,		/* Since: 0.5.10 */
	AS_APP_KIND_SOURCE,		/* Since: 0.5.10 */
	AS_APP_KIND_ADDON,		/* Since: 0.5.10 */
	AS_APP_KIND_FIRMWARE,		/* Since: 0.5.10 */
	AS_APP_KIND_RUNTIME,		/* Since: 0.5.10 */
	AS_APP_KIND_GENERIC,		/* Since: 0.5.10 */
	AS_APP_KIND_OS_UPDATE,		/* Since: 0.5.10 */
	AS_APP_KIND_OS_UPGRADE,		/* Since: 0.5.10 */
	AS_APP_KIND_SHELL_EXTENSION,	/* Since: 0.5.10 */
	AS_APP_KIND_LOCALIZATION,	/* Since: 0.5.11 */
	/*< private >*/
	AS_APP_KIND_LAST
} AsAppKind;

/**
 * AsAppQuirk:
 * @AS_APP_QUIRK_NONE:			No special attributes
 * @AS_APP_QUIRK_PROVENANCE:		Installed by OS vendor
 * @AS_APP_QUIRK_COMPULSORY:		Cannot be removed
 * @AS_APP_QUIRK_HAS_SOURCE:		Has a source to allow staying up-to-date
 * @AS_APP_QUIRK_MATCH_ANY_PREFIX:	Matches applications with any prefix
 * @AS_APP_QUIRK_NEEDS_REBOOT:		A reboot is required after the action
 * @AS_APP_QUIRK_NOT_REVIEWABLE:	The app is not reviewable
 * @AS_APP_QUIRK_HAS_SHORTCUT:		The app has a shortcut in the system
 * @AS_APP_QUIRK_NOT_LAUNCHABLE:	The app is not launchable (run-able)
 *
 * The component attributes.
 **/
typedef enum {
	AS_APP_QUIRK_NONE		= 0,		/* Since: 0.5.10 */
	AS_APP_QUIRK_PROVENANCE		= 1 << 0,	/* Since: 0.5.10 */
	AS_APP_QUIRK_COMPULSORY		= 1 << 1,	/* Since: 0.5.10 */
	AS_APP_QUIRK_HAS_SOURCE		= 1 << 2,	/* Since: 0.5.10 */
	AS_APP_QUIRK_MATCH_ANY_PREFIX	= 1 << 3,	/* Since: 0.5.12 */
	AS_APP_QUIRK_NEEDS_REBOOT	= 1 << 4,	/* Since: 0.5.14 */
	AS_APP_QUIRK_NOT_REVIEWABLE	= 1 << 5,	/* Since: 0.5.14 */
	AS_APP_QUIRK_HAS_SHORTCUT	= 1 << 6,	/* Since: 0.5.15 */
	AS_APP_QUIRK_NOT_LAUNCHABLE	= 1 << 7,	/* Since: 0.5.15 */
	/*< private >*/
	AS_APP_QUIRK_LAST
} AsAppQuirk;

/**
 * AsAppState:
 * @AS_APP_STATE_UNKNOWN:			Unknown state
 * @AS_APP_STATE_INSTALLED:			Application is installed
 * @AS_APP_STATE_AVAILABLE:			Application is available
 * @AS_APP_STATE_AVAILABLE_LOCAL:		Application is locally available as a file
 * @AS_APP_STATE_UPDATABLE:			Application is installed and updatable
 * @AS_APP_STATE_UNAVAILABLE:			Application is referenced, but not available
 * @AS_APP_STATE_QUEUED_FOR_INSTALL:		Application is queued for install
 * @AS_APP_STATE_INSTALLING:			Application is being installed
 * @AS_APP_STATE_REMOVING:			Application is being removed
 * @AS_APP_STATE_UPDATABLE_LIVE:		Application is installed and updatable live
 *
 * The application state.
 **/
typedef enum {
	AS_APP_STATE_UNKNOWN,				/* Since: 0.2.2 */
	AS_APP_STATE_INSTALLED,				/* Since: 0.2.2 */
	AS_APP_STATE_AVAILABLE,				/* Since: 0.2.2 */
	AS_APP_STATE_AVAILABLE_LOCAL,			/* Since: 0.2.2 */
	AS_APP_STATE_UPDATABLE,				/* Since: 0.2.2 */
	AS_APP_STATE_UNAVAILABLE,			/* Since: 0.2.2 */
	AS_APP_STATE_QUEUED_FOR_INSTALL,		/* Since: 0.2.2 */
	AS_APP_STATE_INSTALLING,			/* Since: 0.2.2 */
	AS_APP_STATE_REMOVING,				/* Since: 0.2.2 */
	AS_APP_STATE_UPDATABLE_LIVE,			/* Since: 0.5.4 */
	/*< private >*/
	AS_APP_STATE_LAST
} AsAppState;

#define	AS_APP_ERROR				as_app_error_quark ()

AsApp		*as_app_new			(void);
GQuark		 as_app_error_quark		(void);
AsAppSourceKind	 as_app_guess_source_kind	(const gchar	*filename);
AsAppSourceKind	 as_app_source_kind_from_string	(const gchar	*source_kind);
const gchar	*as_app_source_kind_to_string	(AsAppSourceKind source_kind);
const gchar	*as_app_state_to_string		(AsAppState	 state);
const gchar	*as_app_kind_to_string		(AsAppKind	 kind);
AsAppKind	 as_app_kind_from_string	(const gchar	*kind);

/* getters */
AsAppKind	 as_app_get_kind		(AsApp		*app);
AsAppSourceKind	 as_app_get_source_kind		(AsApp		*app);
AsAppState	 as_app_get_state		(AsApp		*app);
AsAppTrustFlags	 as_app_get_trust_flags		(AsApp		*app);
GList		*as_app_get_languages		(AsApp		*app);
GPtrArray	*as_app_get_addons		(AsApp		*app);
GPtrArray	*as_app_get_categories		(AsApp		*app);
GPtrArray	*as_app_get_compulsory_for_desktops (AsApp	*app);
GPtrArray	*as_app_get_extends		(AsApp		*app);
GPtrArray	*as_app_get_keywords		(AsApp		*app,
						 const gchar	*locale);
GPtrArray	*as_app_get_kudos		(AsApp		*app);
GPtrArray	*as_app_get_permissions		(AsApp		*app);
GPtrArray	*as_app_get_mimetypes		(AsApp		*app);
GPtrArray	*as_app_get_pkgnames		(AsApp		*app);
GPtrArray	*as_app_get_architectures	(AsApp		*app);
GPtrArray	*as_app_get_releases		(AsApp		*app);
GPtrArray	*as_app_get_provides		(AsApp		*app);
GPtrArray	*as_app_get_screenshots		(AsApp		*app);
GPtrArray	*as_app_get_content_ratings	(AsApp		*app);
GPtrArray	*as_app_get_icons		(AsApp		*app);
GPtrArray	*as_app_get_bundles		(AsApp		*app);
GPtrArray	*as_app_get_translations	(AsApp		*app);
GHashTable	*as_app_get_names		(AsApp		*app);
GHashTable	*as_app_get_comments		(AsApp		*app);
GHashTable	*as_app_get_developer_names	(AsApp		*app);
GHashTable	*as_app_get_metadata		(AsApp		*app);
GHashTable	*as_app_get_descriptions	(AsApp		*app);
GHashTable	*as_app_get_urls		(AsApp		*app);
GPtrArray	*as_app_get_vetos		(AsApp		*app);
const gchar	*as_app_get_icon_path		(AsApp		*app);
const gchar	*as_app_get_id_filename		(AsApp		*app);
const gchar	*as_app_get_id			(AsApp		*app);
const gchar	*as_app_get_id_no_prefix	(AsApp		*app);
const gchar	*as_app_get_pkgname_default	(AsApp		*app);
const gchar	*as_app_get_source_pkgname	(AsApp		*app);
const gchar	*as_app_get_origin		(AsApp		*app);
const gchar	*as_app_get_project_group	(AsApp		*app);
const gchar	*as_app_get_project_license	(AsApp		*app);
const gchar	*as_app_get_metadata_license	(AsApp		*app);
const gchar	*as_app_get_update_contact	(AsApp		*app);
const gchar	*as_app_get_source_file		(AsApp		*app);
const gchar	*as_app_get_name		(AsApp		*app,
						 const gchar	*locale);
const gchar	*as_app_get_comment		(AsApp		*app,
						 const gchar	*locale);
const gchar	*as_app_get_developer_name	(AsApp		*app,
						 const gchar	*locale);
const gchar	*as_app_get_description		(AsApp		*app,
						 const gchar	*locale);
gint		 as_app_get_priority		(AsApp		*app);
gint		 as_app_get_language		(AsApp		*app,
						 const gchar	*locale);
const gchar	*as_app_get_metadata_item	(AsApp		*app,
						 const gchar	*key);
const gchar	*as_app_get_url_item		(AsApp		*app,
						 AsUrlKind	 url_kind);
gboolean	 as_app_has_category		(AsApp		*app,
						 const gchar	*category);
gboolean	 as_app_has_kudo		(AsApp		*app,
						 const gchar	*kudo);
gboolean	 as_app_has_kudo_kind		(AsApp		*app,
						 AsKudoKind	 kudo);
gboolean	 as_app_has_permission		(AsApp		*app,
						 const gchar	*permission);
gboolean	 as_app_has_compulsory_for_desktop (AsApp	*app,
						 const gchar	*desktop);
gboolean	 as_app_has_quirk		(AsApp		*app,
						 AsAppQuirk	 quirk);

/* setters */
void		 as_app_set_id			(AsApp		*app,
						 const gchar	*id);
void		 as_app_set_kind		(AsApp		*app,
						 AsAppKind	 kind);
void		 as_app_set_source_kind		(AsApp		*app,
						 AsAppSourceKind source_kind);
void		 as_app_set_state		(AsApp		*app,
						 AsAppState	 state);
void		 as_app_set_trust_flags		(AsApp		*app,
						 AsAppTrustFlags trust_flags);
void		 as_app_set_origin		(AsApp		*app,
						 const gchar	*origin);
void		 as_app_set_project_group	(AsApp		*app,
						 const gchar	*project_group);
void		 as_app_set_project_license	(AsApp		*app,
						 const gchar	*project_license);
void		 as_app_set_metadata_license	(AsApp		*app,
						 const gchar	*metadata_license);
void		 as_app_set_source_pkgname	(AsApp		*app,
						 const gchar	*source_pkgname);
void		 as_app_set_update_contact	(AsApp		*app,
						 const gchar	*update_contact);
void		 as_app_set_icon_path		(AsApp		*app,
						 const gchar	*icon_path);
void		 as_app_set_name		(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*name);
void		 as_app_set_comment		(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*comment);
void		 as_app_set_developer_name	(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*developer_name);
void		 as_app_set_description		(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*description);
void		 as_app_set_source_file		(AsApp		*app,
						 const gchar	*source_file);
void		 as_app_set_priority		(AsApp		*app,
						 gint		 priority);
void		 as_app_add_category		(AsApp		*app,
						 const gchar	*category);
void		 as_app_add_keyword		(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*keyword);
void		 as_app_add_kudo		(AsApp		*app,
						 const gchar	*kudo);
void		 as_app_add_kudo_kind		(AsApp		*app,
						 AsKudoKind	 kudo_kind);
void		 as_app_add_permission		(AsApp		*app,
						 const gchar	*permission);
void		 as_app_add_mimetype		(AsApp		*app,
						 const gchar	*mimetype);
void		 as_app_add_pkgname		(AsApp		*app,
						 const gchar	*pkgname);
void		 as_app_add_arch		(AsApp		*app,
						 const gchar	*arch);
void		 as_app_add_release		(AsApp		*app,
						 AsRelease	*release);
void		 as_app_add_provide		(AsApp		*app,
						 AsProvide	*provide);
void		 as_app_add_screenshot		(AsApp		*app,
						 AsScreenshot	*screenshot);
void		 as_app_add_content_rating	(AsApp		*app,
						 AsContentRating *content_rating);
void		 as_app_add_icon		(AsApp		*app,
						 AsIcon		*icon);
void		 as_app_add_bundle		(AsApp		*app,
						 AsBundle	*bundle);
void		 as_app_add_translation		(AsApp		*app,
						 AsTranslation	*translation);
void		 as_app_add_language		(AsApp		*app,
						 gint		 percentage,
						 const gchar	*locale);
void		 as_app_add_compulsory_for_desktop (AsApp	*app,
						 const gchar	*compulsory_for_desktop);
void		 as_app_add_url			(AsApp		*app,
						 AsUrlKind	 url_kind,
						 const gchar	*url);
void		 as_app_add_metadata		(AsApp		*app,
						 const gchar	*key,
						 const gchar	*value);
void		 as_app_remove_metadata		(AsApp		*app,
						 const gchar	*key);
void		 as_app_add_addon		(AsApp		*app,
						 AsApp		*addon);
void		 as_app_add_extends		(AsApp		*app,
						 const gchar	*extends);
void		 as_app_add_quirk		(AsApp		*app,
						 AsAppQuirk	 quirk);

/* object methods */
GPtrArray	*as_app_validate		(AsApp		*app,
						 AsAppValidateFlags flags,
						 GError		**error);
void		 as_app_subsume			(AsApp		*app,
						 AsApp		*donor);
void		 as_app_subsume_full		(AsApp		*app,
						 AsApp		*donor,
						 AsAppSubsumeFlags flags);
void		 as_app_add_veto		(AsApp		*app,
						 const gchar	*fmt,
						 ...)
						 G_GNUC_PRINTF(2,3);
void		 as_app_remove_veto		(AsApp		*app,
						 const gchar	*description);
guint		 as_app_search_matches_all	(AsApp		*app,
						 gchar		**search);
guint		 as_app_search_matches		(AsApp		*app,
						 const gchar	*search);
gboolean	 as_app_parse_file		(AsApp		*app,
						 const gchar	*filename,
						 AsAppParseFlags flags,
						 GError		**error);
gboolean	 as_app_to_file			(AsApp		*app,
						 GFile		*file,
						 GCancellable	*cancellable,
						 GError		**error);
AsContentRating	*as_app_get_content_rating	(AsApp		*app,
						 const gchar 	*kind);
AsIcon		*as_app_get_icon_default	(AsApp		*app);
AsIcon		*as_app_get_icon_for_size	(AsApp		*app,
						 guint		 width,
						 guint		 height);
AsBundle	*as_app_get_bundle_default	(AsApp		*app);
AsRelease	*as_app_get_release		(AsApp		*app,
						 const gchar	*version);
AsRelease	*as_app_get_release_default	(AsApp		*app);
gboolean	 as_app_convert_icons		(AsApp		*app,
						 AsIconKind	 kind,
						 GError		**error);

/* deprecated */
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
AsIdKind	 as_app_get_id_kind		(AsApp		*app)
G_DEPRECATED_FOR(as_app_get_kind);
void		 as_app_set_id_kind		(AsApp		*app,
						 AsIdKind	 id_kind)
G_DEPRECATED_FOR(as_app_set_kind);
G_GNUC_END_IGNORE_DEPRECATIONS

G_END_DECLS

#endif /* __AS_APP_H */
