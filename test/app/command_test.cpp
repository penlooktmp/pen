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
#include <app/command/output.h>
#include <app/command/parser.h>

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

	Command *cmd = new Command();
	cmd ->setName("send:email")
		->setDescription("Send email for verification")
		->addArgument((new InputArgument())
			->setName("sender")
			->setDescription("Sender address")
			->setDefault("loint@gmail.com")
		)
		->addArgument((new InputArgument())
			->setName("reciever")
			->setDescription("Reciever address")
			->setDefault("abc@gmail.com")
		)
		->addOption((new InputOption())
			->setName("force")
			->setRequired(true)
		)
		->addOption((new InputOption())
			->setName("env")
			->setDescription("Environment variable")
			->setRequired(false)
			->setDefault("staging")
		);

	// Assertion
	EXPECT_EQ("send:email", cmd->getName());
	EXPECT_EQ("Send email for verification", cmd->getDescription());
	EXPECT_EQ(2, cmd->getArgumentList().size());
	EXPECT_EQ(2, cmd->getOptionList().size());
	delete cmd;
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
	delete arg;
}

TEST_F(CommandTest, InputOptionTest)
{
	InputOption *option = new InputOption();
	option->setName("send:email")
		  ->setAlias('s')
		  ->setDescription("Send email to customer")
		  ->setDefault("root@localhost")
		  ->setRequired(true);
	EXPECT_EQ("send:email", option->getName());
	EXPECT_EQ('s', option->getAlias());
	EXPECT_EQ("Send email to customer", option->getDescription());
	EXPECT_EQ("root@localhost", option->getDefault());
	EXPECT_EQ(true, option->getRequired());
	delete option;
}

TEST_F(CommandTest, InputOptionListTest)
{
	InputOptionList optionList;
	optionList["send:email"] = new InputOption();
	optionList["send:sms"] = new InputOption();
	optionList["send:notification"] = new InputOption();
	EXPECT_EQ(3, optionList.size());
	optionList.clear();
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

class GreetCommand : public Command
{
	public:
		void configure()
		{
			this->setName("greet")
				->setDescription("Greet somebody !");
		}
		
		void execute(Input *input, Output *output)
		{
			output->println("Greet Loi !");
		}
};

class AskCommand : public Command
{
	public:
		void configure()
		{
			this->setName("ask")
				->setDescription("Ask me a question !")
				->addArgument((new InputArgument())
					->setName("question")
					->setDescription("Question")
				)
				->addArgument((new InputArgument())
					->setName("answser")
					->setDescription("Answer")
				)
				->addOption((new InputOption())
					->setName("flag")
					->setDescription("Ask flag")
					->setRequired(true)
				);
			
		}
		
		void execute(Input *input, Output *output)
		{
			
		}
};

TEST_F(CommandTest, Sample)
{
	GreetCommand *greetCmd = new GreetCommand();
	greetCmd->configure();
	EXPECT_EQ("greet", greetCmd->getName());
	delete greetCmd;
	
	AskCommand *askCmd = new AskCommand();
	askCmd->configure();
	EXPECT_EQ("ask", askCmd->getName());
	delete askCmd;
}

TEST_F(CommandTest, Cli)
{
	Cli *cli = new Cli();
	cli	->addCommand(new GreetCommand())
		->addCommand(new AskCommand());
	CommandList cmdList = cli->getCommandList();

	// Assert number of command
	EXPECT_EQ(2, cmdList.size());

	Command *greet = cmdList["greet"];
	Command *ask   = cmdList["ask"];

	// Assert greet command
	EXPECT_EQ("greet", greet->getName());
	EXPECT_EQ("Greet somebody !", greet->getDescription());

	Input  *input  = new Input();
	Output *output = new Output();
	greet->execute(input, output);
	EXPECT_EQ("Greet Loi !\n", output->getContent());

	delete input;
	delete output;
	delete cli;
}

TEST_F(CommandTest, Parser)
{
	Cli *cli = new Cli();
	cli	->addCommand(new GreetCommand())
		->addCommand(new AskCommand());
	int argc = 6;
	char* argv[6] = {
		(char*) "/usr/bin/app",
		(char*) "ask",
		(char*) "How are you ?",
		(char*) "Fine.",
		(char*) "--flag=abc",
		'\0'
	};
	cli->parse(argc, argv);
	EXPECT_EQ(4, len(cli->getArguments()));
	EXPECT_EQ(3, cli->getParser()->rest().size());
	EXPECT_EQ("abc", cli->getParser()->get<string>("flag"));
	delete cli;
}

TEST_F(CommandTest, CommandIO)
{
	Cli    *cli    = new Cli();
	Input  *input  = (new Input())
						->addOption((new InputOption())
							->setName("option1")
						)
						->addOption((new InputOption())
							->setName("option2")
						);
			
	Output *output = new Output();
	output->appendContent("test1 ")
		  ->appendContent("test2");

	cli ->setInput(input)
		->setOutput(output);

	ASSERT_EQ(2,  cli->getInput()->getOptionList().size());
	ASSERT_EQ("test1 test2", cli->getOutput()->getContent());

	delete cli;
	delete input;
	delete output;
}