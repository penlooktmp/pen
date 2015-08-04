/**
 * Pengo Project
 *
 * Copyright (c) 2015 Penlook Development Team
 *
 * --------------------------------------------------------------------
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * Author:
 *     Loi Nguyen       <loint@penlook.com>
 */

#include <limits.h>
#include <gtest/gtest.h>
#include <sys/func.h>
#include <app/command.h>
#include <app/command/input.h>

using namespace app;
using namespace app::command;

class CommandTest : public ::testing::Test
{
	protected:
		virtual void SetUp() {}
		virtual void TearDown() {}
};

TEST_F(CommandTest, Command)
{
	// app send:email loint@penlook.com tinntt@penlook.com --force --env=production

	Command *cmd = new Command;
	cmd ->setName("send:email")
		->setDescription("Send email for verification")
		->addArgument("sender")
		->addArgument("reciever", "Receiver email")
		->addOption("force", "Force excution", InputOption::FLAGONLY)
		->addOption("env",   "Environment variable", InputOption::REQUIRED, "staging");

	EXPECT_EQ("send:email", cmd->getName());
	EXPECT_EQ("Send email for verification", cmd->getDescription());
	EXPECT_EQ(2, cmd->getArguments().size());
	EXPECT_EQ(2, cmd->getOptions().size());
}

TEST_F(CommandTest, InputArgument)
{
	InputArgument *arg = new InputArgument;
	arg->setName("argument1")
	   ->setDescription("First argument")
	   ->setValue("loint@penlook.com");

	EXPECT_EQ("argument1", arg->getName());
	EXPECT_EQ("First argument", arg->getDescription());
	EXPECT_EQ("loint@penlook.com", arg->getValue());
}

TEST_F(CommandTest, InputOption)
{
	//InputArgument arg = new InputOption;
	EXPECT_EQ("TEST", "TEST");
}

TEST_F(CommandTest, Output)
{
	//InputArgument arg = new InputOption;
	EXPECT_EQ("TEST", "TEST");
}

TEST_F(CommandTest, CommandExcution)
{
	//InputArgument arg = new InputArgument;
	EXPECT_EQ("TEST", "TEST");
}
