/* $Id: title_screen.hpp 48740 2011-03-05 10:01:34Z mordante $ */
/*
   Copyright (C) 2008 - 2011 by Mark de Wever <koraq@xs4all.nl>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#ifndef GUI_DIALOGS_TITLE_SCREEN_HPP_INCLUDED
#define GUI_DIALOGS_TITLE_SCREEN_HPP_INCLUDED

#include "gui/dialogs/dialog.hpp"
#include "multiplayer.hpp"

class game_display;
class hero_map;
class hero;

namespace gui2 {

/**
 * This class implements the title screen.
 *
 * The menu buttons return a result back to the caller with the button pressed.
 * So at the moment it only handles the tips itself.
 *
 * @todo Evaluate whether we can handle more buttons in this class.
 */
class ttitle_screen : public tdialog
{
public:
	ttitle_screen(game_display& gui, hero_map& heros, hero& player_hero);

	~ttitle_screen();

	/**
	 * Values for the menu-items of the main menu.
	 *
	 * @todo Evaluate the best place for these items.
	 */
	enum tresult {
			  TUTORIAL = 1        /**< Start special campaign 'tutorial' */
			, NEW_CAMPAIGN        /**< Let user select a campaign to play */
			, RANDOM_MAP
			, MULTIPLAYER         /**<
			                       * Play single scenario against humans or AI
			                       */
			, LOAD_GAME
			, GET_ADDONS
			, START_MAP_EDITOR
			, CHANGE_LANGUAGE
			, EDIT_PREFERENCES
			, INAPP_PURCHASE
			, SHOW_ABOUT          /**< Show credits */
			, QUIT_GAME
			, SHOW_HELP
			, NOTHING             /**<
			                       * Default, nothing done, no redraw needed
			                       */
			};

private:

	/** Inherited from tdialog, implemented by REGISTER_DIALOG. */
	virtual const std::string& window_id() const;

	/** Inherited from tdialog. */
	virtual void post_build(CVideo& video, twindow& window);

	/** Inherited from tdialog. */
	void pre_show(CVideo& video, twindow& window);

	void post_show(twindow& window);

	void report(twindow& window);
	void player(twindow& window);

	void version_2_plug(twindow& window) const;
private:
	game_display& gui_;
	hero_map& heros_;
	hero& player_hero_;
	static http::membership member;
};

} // namespace gui2

#endif
